#include <array>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <math.h>
#include <SOIL2/SOIL2.h>
#include <string>
#include <vector>


using namespace std;

extern void cleanUpScene();

GLFWwindow		*window;

// normal keys are fom [0..255], arrow and special keys are from [256..511]
GLboolean		keyboard[512] = {GL_FALSE};

int				window_width = 600;
int				window_height = 600;
char			window_title[] = "Brick texture";

// 6 darab h�romsz�gb�l fel�p�tett g�la.
float vertices[] = {
	// a pal�st
	// szemk�zti h�romsz�ge
	-1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, 1.0f,
	0.0f, 1.0f, 0.0f,
	// jobb oldali h�romsz�ge
	1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, -1.0f,
	0.0f, 1.0f, 0.0f,
	// h�tuls� oldali h�romsz�ge
	1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	0.0f, 1.0f, 0.0f,
	// bal oldali h�romsz�ge
	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, 1.0f,
	0.0f, 1.0f, 0.0f,

	// az alaplap egy n�gyzet
	-1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f,

	1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
};

float texCoords[] = {
	/** A modell�nket alkot� valamennyi vertex sz�m�ra megadjuk a text�ra-koordin�ta �rt�keket.
	Az itt megadott �rt�kek a text�r�z�shoz felhaszn�lt k�p pixeleire (texel) hivatkoznak, vagyis
	itt defini�ljuk, hogy a 3D modell�nk (x,y,z) �rt�kh�rmassal adott pontj�nak sz�n�t melyik 
	(s,t) koordin�t�kkal jel�lt texel adja meg.*/
	0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f,
	0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f,
	0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f,
	0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f
};

GLuint myTexture;

/* Vertex buffer objektum �s vertex array objektum az adatt�rol�shoz.
   VBO2 a text�ra sz�m�ra defini�lt, �j objektum lesz. */
/* Vertex buffer objektum �s vertex array objektum az adatt�rol�shoz.*/
#define numVBOs	2
#define numVAOs	1
GLuint			VBO[numVBOs];
GLuint			VAO[numVAOs];

GLuint			renderingProgram;

unsigned int	modelLoc;
unsigned int	viewLoc;
unsigned int	projectionLoc;

glm::mat4		model, view, projection = glm::perspective(glm::radians(45.0f), (float)window_width / (float)window_height, 0.1f, 100.0f);
glm::mat4		rotateM, scaleM; // invTmatrix,

GLdouble		currentTime, deltaTime = 0.0f, lastTime = 0.0f;

glm::vec3		cameraPos		= glm::vec3( 0.0f, 0.0f, 3.0f),
				cameraTarget	= glm::vec3( 0.0f, 0.0f, 0.0f),
				cameraUp		= glm::vec3( 0.0f, 1.0f, 0.0f),
				cameraMovingX	= glm::vec3(-1.0f, 0.0f, 0.0f),
				cameraMovingY	= glm::vec3( 0.0f, 1.0f, 0.0f);
//glm::vec3		lightPos;

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

GLuint loadTexture(const char* texturePath) {
	GLuint		textureID;

	/* Text�ra objektum gener�l�sa
	A lehets�ges argomentumok list�j�t a SOIL2.h �llom�nyban szerepl� dokument�ci� r�szletezi. */
	textureID = SOIL_load_OGL_texture(texturePath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (textureID == 0) {
		cout << "Error: could not find texture image" << endl;
		cleanUpScene();
	}

	glBindTexture(GL_TEXTURE_2D, textureID);

	/* Vizsg�ljuk meg mi t�rt�nik, ha a text�ra-koordin�t�k defini�l�sa sor�n a [-2..2] intervallumb�l 
	v�lasztunk �rt�keket a jelenlegi [0..1] intervallum helyett, majd aktiv�ljuk 
	az 1. vagy a 2. esethez tartoz� k�dsorokat! */

	/* 1. eset */
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	/* 2. eset */
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	//float borderColor[4] = {0.0f, 1.0f, 0.0f, 1.0f};
	//glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	
	/* A text�ra pixelek interpol�l�sa: sz�r�si be�ll�t�sok.
	1. TEXTURE_MAG_FILTER: Ha a poligonunk nagyobb a text�ra k�p�n�l.
	2. TEXTURE_MIN_FILTER: Ha a poligonunk kisebb mint a text�ra k�pe. 
	R�szletesebben pl itt olvashatunk ut�na: https://www.khronos.org/opengl/wiki/Sampler_Object
	*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);				// GL_NEAREST
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	/* Mipmap szintek legener�l�sa. */
	glGenerateMipmap(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, 0);

	return textureID;
}

void computeModelMatrix() {
	rotateM	= glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	scaleM	= glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 0.5f, 1.0f));
	model	= rotateM * scaleM;
}

void computeCameraMatrix() {
	view	= glm::lookAt(cameraPos, cameraTarget, cameraUp);
}

void init(GLFWwindow* window) {
	renderingProgram = createShaderProgram();

	/* Text�ra objektum l�trehoz�sa. */
	myTexture = loadTexture("brick.jpg");

	/* L�trehozzuk a sz�ks�ges Vertex buffer �s vertex array objektumot, egyet a text�ra sz�m�ra is. */
	glGenBuffers(numVBOs, VBO);
	glGenVertexArrays(numVAOs, VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/* A text�ra-koordin�t�k �tm�sol�sa a VBO[1] pufferbe. */
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

	glBindVertexArray(VAO[0]);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glUseProgram(renderingProgram);

	modelLoc		= glGetUniformLocation(renderingProgram, "model");
	viewLoc			= glGetUniformLocation(renderingProgram, "view");
	projectionLoc	= glGetUniformLocation(renderingProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	/* A fragment shader�nk sz�m�ra biztos�tjuk a text�ra objektumhoz a hozz�f�r�st (uniform sampler variable). */
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, myTexture);
}

/** A jelenet�nk ut�ni takar�t�s. */
void cleanUpScene() {
	/* t�r�lj�k a GLFW ablakot. */
	glfwDestroyWindow(window);

	/** T�r�lj�k a vertex puffer �s vertex array objektumokat. */
	glDeleteVertexArrays(numVAOs, VAO);
	glDeleteBuffers(numVBOs, VBO);

	/** T�r�lj�k a shader programot. */
	glDeleteProgram(renderingProgram);

	/* Le�ll�tjuk a GLFW-t */
	glfwTerminate();

	exit(EXIT_SUCCESS);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float currentTime = glfwGetTime();
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	float cameraSpeed = 5.0f * deltaTime;

//	printf("%g\n", currentTime);

	/* A kamera sz�m�ra sz�m�tsuk ki az el�re mutat� ir�nyt .*/
	if ((keyboard[GLFW_KEY_W]) || (keyboard[GLFW_KEY_UP]))
		cameraPos += cameraSpeed * cameraMovingY;

	if ((keyboard[GLFW_KEY_S]) || (keyboard[GLFW_KEY_DOWN]))
		cameraPos -= cameraSpeed * cameraMovingY;

	if ((keyboard[GLFW_KEY_A]) || (keyboard[GLFW_KEY_LEFT]))
		cameraPos += cameraSpeed * cameraMovingX;

	if ((keyboard[GLFW_KEY_D]) || (keyboard[GLFW_KEY_RIGHT]))
		cameraPos -= cameraSpeed * cameraMovingX;

//	lightPos = cameraPos;

	computeModelMatrix();
	computeCameraMatrix();

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	glBindVertexArray(VAO[0]);

	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));

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

	/* A k�v�nt OpenGL verzi� (4.3) */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, nullptr, nullptr);

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	glfwSetKeyCallback(window, keyCallback);

	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window)) {
		display();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	cleanUpScene();

	return EXIT_SUCCESS;
}