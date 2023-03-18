// https://www.khronos.org/opengl/wiki/Geometry_Shader
// https://github.com/JoeyDeVries/LearnOpenGL/blob/bc41d2c0192220fb146c5eabf05f3d8317851200/src/4.advanced_opengl/9.1.geometry_shader_houses/9.1.geometry_shader.gs
#include <array>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

extern void cleanUpScene();

GLFWwindow		*window;

GLboolean		keyboard[512] = { GL_FALSE };

int				window_width = 600;
int				window_height = 600;
char			window_title[] = "Parametric surface";

/* Vertex buffer objektum és vertex array objektum az adattároláshoz.*/
#define numIBOs 1
#define numVBOs 1
#define numVAOs 1
GLuint			IBO[numIBOs];
GLuint			VBO[numVBOs];
GLuint			VAO[numVAOs];

GLuint			renderingProgram;

unsigned int	modelLoc;
unsigned int	viewLoc;
unsigned int	projectionLoc;

/** Vetítési és kamera mátrixok felvétele. */
glm::mat4		model, view, projection = glm::perspective(glm::radians(45.0f), (float)window_width / (float)window_height, 0.1f, 100.0f);
glm::mat4		rotateM, scaleM, translateM;

GLdouble		currentTime, 
				deltaTime = 0.0f, 
				lastTime = 0.0f;

/* Vegyük fel a kamera pozicót tároló változót, illetve a tengelyekhezz szükséges vektorokat. */
glm::vec3		cameraPos = glm::vec3(0.0f, 0.0f, 3.0f), 
				cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f), 
				up = glm::vec3(0.0f, 1.0f, 0.0f),
				cameraMoving = glm::vec3(0.0, 0.0, -1.0);

static std::vector<glm::vec3>	surface_vertices;
static std::vector<GLuint>		surface_indices;

bool checkOpenGLError() {
	bool foundError = false;
	int glErr = glGetError();
	while (glErr != GL_NO_ERROR) {
		cout << "glError: " << glErr << endl;
		foundError = true;
		glErr = glGetError();
	}
	return foundError;
}

void printShaderLog(GLuint shader) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetShaderInfoLog(shader, len, &chWrittn, log);
		cout << "Shader Info Log: " << log << endl;
		free(log);
	}
}

void printProgramLog(int prog) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetProgramInfoLog(prog, len, &chWrittn, log);
		cout << "Program Info Log: " << log << endl;
		free(log);
	}
}

string readShaderSource(const char* filePath) {
	string content;
	ifstream fileStream(filePath, ios::in);
	string line = "";

	while (!fileStream.eof()) {
		getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}

GLuint createShaderProgram() {

	GLint vertCompiled;
	GLint fragCompiled;
	GLint linked;

	string vertShaderStr = readShaderSource("vertexShader.glsl");
	string fragShaderStr = readShaderSource("fragmentShader.glsl");

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();

	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);

	glCompileShader(vShader);
	checkOpenGLError();
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
	if (vertCompiled != 1) {
		cout << "vertex compilation failed" << endl;
		printShaderLog(vShader);
	}

	glCompileShader(fShader);
	checkOpenGLError();
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &fragCompiled);
	if (fragCompiled != 1) {
		cout << "fragment compilation failed" << endl;
		printShaderLog(fShader);
	}

	// Shader program objektum létrehozása. Eltároljuk az ID értéket.
	GLuint vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);

	glLinkProgram(vfProgram);
	checkOpenGLError();
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
	if (linked != 1) {
		cout << "linking failed" << endl;
		printProgramLog(vfProgram);
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);

	return vfProgram;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if ((action == GLFW_PRESS) && (key == GLFW_KEY_ESCAPE))
		cleanUpScene();

	if (action == GLFW_PRESS)
		keyboard[key] = GL_TRUE;
	else if (action == GLFW_RELEASE)
		keyboard[key] = GL_FALSE;
}

/* A formális paraméterek megadják, hogy hány darab lapból építjük fel a felületet. */
void generateSurfacePoints(int numHorizontalFaces, int numVerticalFaces) {

	/* Lépésköz kiszámolása. */
	float horizontalStep = glm::radians(360.0f) / numHorizontalFaces;
	float verticalStep = glm::radians(360.0f) / numVerticalFaces;

//	glm::vec3 center = glm::vec3(0.0f);

	/* Csúcspontok elõállítása. */
	for (int i = 0; i <= numVerticalFaces; ++i) {
		for (int j = 0; j <= numHorizontalFaces; ++j) {
			float u = i * verticalStep;
			float v = j * horizontalStep;

			glm::vec3 vertex = glm::vec3(
				(2.5f + 1.0 * glm::cos(u)) * glm::cos(v),
				(2.5f + 1.0 * glm::cos(u)) * glm::sin(v),
				 1.0 * glm::sin(u)
			);

			surface_vertices.push_back(vertex);
		}
	}

	/* Indexek elõállítása: a lapok háromszögeit alkotó egyes csúcspontok azonosítóját keressük. */
	for (int i = 0; i < numVerticalFaces; ++i) {
		for (int j = 0; j < numHorizontalFaces; ++j) {

			/* Relatív lap indexek, ahol az (i, j) indexû csúcs a bal alsó sarok lesz.  */
			static glm::ivec2 SURFACE_INDICES[] = {

				 glm::ivec2(0, 0),
				 glm::ivec2(1, 0),
				 glm::ivec2(1, 1),
				 glm::ivec2(0, 0),
				 glm::ivec2(1, 1),
				 glm::ivec2(0, 1)
			};

			for (int k = 0; k < size(SURFACE_INDICES); ++k) {
				glm::ivec2 relIndices = SURFACE_INDICES[k];
				int vertexId = (i + relIndices[1]) * (numHorizontalFaces + 1) + j + relIndices[0];
				surface_indices.push_back(vertexId);
			}
		}
	}
}

void computeModelMatrices() {
	scaleM = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	translateM = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
	rotateM = glm::rotate(glm::mat4(1.0f), float(glfwGetTime() / 2.5f), glm::vec3(0.0, 1.0, 0.0));
	model = translateM * rotateM * scaleM;
}

void computeCameraMatrix() {
	view = glm::lookAt(cameraPos, cameraPos + cameraMoving, up);
}

void init(GLFWwindow* window) {

	renderingProgram = createShaderProgram();

	generateSurfacePoints(64, 32);

	/* Létrehozzuk a szükséges Vertex buffer és vertex array objektumot. */
	glGenBuffers(numIBOs, IBO);
	glGenBuffers(numVBOs, VBO);
	glGenVertexArrays(numVAOs, VAO);

	/* Típus meghatározása: a GL_ARRAY_BUFFER nevesített csatolóponthoz kapcsoljuk a buffert (ide kerülnek a vertex adatok). */
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);

	/* Másoljuk az adatokat a pufferbe! Megadjuk az aktuálisan csatolt puffert,  azt hogy hány bájt adatot másolunk,
	a másolandó adatot, majd a feldolgozás módját is meghatározzuk: most az adat nem változik a feltöltés után */
	glBufferData(GL_ARRAY_BUFFER, surface_vertices.size() * sizeof(glm::vec3), surface_vertices.data(), GL_STATIC_DRAW);

	/* A puffer kész, lecsatoljuk, már nem szeretnénk módosítani. */
//	glBindBuffer(GL_ARRAY_BUFFER, 0);


	/* Csatoljuk a vertex array objektumunkat a konfiguráláshoz. */
	glBindVertexArray(VAO[0]);

	/* Vertex buffer objektum újracsatolása. */
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);

	/* Ezen adatok szolgálják a 0 indexû vertex attribútumot (itt: pozíció).
	Elsõként megadjuk ezt az azonosítószámot.
	Utána az attribútum méretét (vec3, láttuk a shaderben).
	Harmadik az adat típusa.
	Negyedik az adat normalizálása, ez maradhat FALSE jelen példában.
	Az attribútum értékek hogyan következnek egymás után? Milyen lépésköz után találom a következõ vertex adatait?
	Végül megadom azt, hogy honnan kezdõdnek az értékek a pufferben. Most rögtön, a legelejétõl veszem õket.*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, surface_indices.size() * sizeof(GLuint), surface_indices.data(), GL_STATIC_DRAW);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO[0]);

	/* Engedélyezzük az imént definiált 0 indexû attribútumot. */
	glEnableVertexAttribArray(0);

	/* Leválasztjuk a vertex array objektumot és a puufert is.*/
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glUseProgram(renderingProgram);

	modelLoc = glGetUniformLocation(renderingProgram, "model");
	viewLoc = glGetUniformLocation(renderingProgram, "view");
	projectionLoc = glGetUniformLocation(renderingProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	GLint		MAX_GEOMETRY_OUTPUT_VERTICES;
	GLint		MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS;
	GLint		MAX_GEOMETRY_OUTPUT_COMPONENTS;

	glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_VERTICES, &MAX_GEOMETRY_OUTPUT_VERTICES);
	glGetIntegerv(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS, &MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS);
	glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS, &MAX_GEOMETRY_OUTPUT_COMPONENTS);

	cout << MAX_GEOMETRY_OUTPUT_VERTICES << " " << MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS << " " << MAX_GEOMETRY_OUTPUT_COMPONENTS;
}

/** A jelenetünk utáni takarítás. */
void cleanUpScene()
{
	/* töröljük a GLFW ablakot. */
	glfwDestroyWindow(window);

	/** Töröljük a vertex puffer és vertex array objektumokat. */
	glDeleteVertexArrays(numVAOs, VAO);
	glDeleteBuffers(numVBOs, VBO);
	glDeleteBuffers(numIBOs, IBO);

	/** Töröljük a shader programot. */
	glDeleteProgram(renderingProgram);

	/* Leállítjuk a GLFW-t */
	glfwTerminate();

	exit(EXIT_SUCCESS);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	currentTime = glfwGetTime();
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	float cameraSpeed = 5.0f * deltaTime;

	if ((keyboard[GLFW_KEY_W]) || (keyboard[GLFW_KEY_UP]))
		cameraPos += cameraSpeed * cameraMoving;

	if ((keyboard[GLFW_KEY_S]) || (keyboard[GLFW_KEY_DOWN]))
		cameraPos -= cameraSpeed * cameraMoving;

	computeModelMatrices();
	computeCameraMatrix();

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	/*Csatoljuk a vertex array objektumunkat. */
	glBindVertexArray(VAO[0]);
	glDrawElements(GL_TRIANGLES, surface_indices.size(), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	window_width = width;
	window_height = height;

	glViewport(0, 0, width, height);

	projection = glm::perspective(glm::radians(45.0f), (float)window_width / (float)window_height, 0.1f, 100.0f);
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

int main(void) {
	if (!glfwInit()) { exit(EXIT_FAILURE); }

	/* A kívánt OpenGL verzió (4.3) */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	/** A közvetlen mód glBegin és glEnd között glVertex hívásokat használ. */
	/** Immediate mode is using glBegin and glEnd with glVertex in between them. */
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//#ifdef __APPLE__ // To make macOS happy; should not be needed.
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif

	GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	glfwSetKeyCallback(window, keyCallback);

	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		display();
		glfwSwapBuffers(window);
	}

	cleanUpScene();

	return EXIT_SUCCESS;
}