/*
https://en.wikipedia.org/wiki/B%C3%A9zier_curve#Explicit_definition
https://en.wikipedia.org/wiki/Factorial
https://hu.wikipedia.org/wiki/Binomi%C3%A1lis_egy%C3%BCtthat%C3%B3
https://hu.frwiki.wiki/wiki/Polyn%C3%B4me_de_Bernstein
https://plus.maths.org/content/not-just-matter-time-part-1
https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
*/
#include <array>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

/* Vektor a görbe pontjainak tárolásához. */
/* Vector for storing the points of a curve. */
std::vector<glm::vec3> pointToDraw;

/* Vektor a görbe kontrollpontjainak tárolásához. */
/* Vector for storing the control points of a curve. */
std::vector<glm::vec3> myControlPoints = {
	glm::vec3(-0.5f, -0.5f, 0.0f),
	glm::vec3(-0.5f,  0.5f, 0.0f),
	glm::vec3( 0.5f, -0.1f, 0.0f),
	glm::vec3( 0.5f,  0.5f, 0.0f),
};

/* Vertex buffer objektum és vertex array objektum az adattároláshoz. */
/* Vertex buffer object ID and vertex array object ID for data storing. */
#define		numVBOs			1
#define		numVAOs			1
GLuint		VBO[numVBOs];
GLuint		VAO[numVAOs];

int			window_width	= 600;
int			window_height	= 600;
char		window_title[]	= "Bezier Curve";
/** A normál billentyûk a [0..255] tartományban vannak, a nyilak és a speciális billentyûk pedig a [256..511] tartományban helyezkednek el. */
/** Normal keys are fom [0..255], arrow and special keys are from [256..511]. */
GLboolean	keyboard[512]	= { GL_FALSE };
GLFWwindow* window			= nullptr;
GLuint		renderingProgram;

bool checkOpenGLError() {
	bool	foundError = false;
	int		glErr = glGetError();

	/** Vizsgáljuk meg, hogy van-e aktuálisan OpenGL hiba, és amennyiben igen, írassuk ki azokat a konzolra egyenként. */
	/** Check for OpenGL errors, and send them to the console ony by one. */
	while (glErr != GL_NO_ERROR) {
		cout << "glError: " << glErr << endl;

		foundError = true;
		glErr = glGetError();
	}

	/** Ha van aktuálisan OpenGL hiba, a visszatérési érték true. */
	/** If there are OpenGL errors, the return value is true. */
	return foundError;
}

void printShaderLog(GLuint shader) {
	int		length = 0;
	int		charsWritten = 0;
	char* log = nullptr;

	/** Vizsgáljuk meg, hogy van-e valami a Shader Info Logban, és amennyiben igen, írassuk ki azt a konzolra soronként. */
	/** Check for Shader Info Log, and send it to the console by lines if it is created for the last compile. */
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

	if (length > 0) {
		log = (char*)malloc(length);

		/** Olvassuk és írassuk ki a következõ sort. */
		/** Read out and and send to the console the next line. */
		glGetShaderInfoLog(shader, length, &charsWritten, log);
		cout << "Shader Info Log: " << log << endl;
		free(log);
	}
}

void printProgramLog(int prog) {
	int		length = 0;
	int		charsWritten = 0;
	char* log = nullptr;

	/** Vizsgáljuk meg, hogy van-e valami a Program Info Logban, és amennyiben igen, írassuk ki azt a konzolra soronként. */
	/** Check for Program Info Log, and send it to the console by lines if it is created for the last compile. */
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &length);

	if (length > 0) {
		log = (char*)malloc(length);

		/** Olvassuk és írassuk ki a következõ sort. */
		/** Read out and and send to the console the next line. */
		glGetProgramInfoLog(prog, length, &charsWritten, log);
		cout << "Program Info Log: " << log << endl;
		free(log);
	}
}

string readShaderSource(const char* filePath) {
	/** A file stream inicializálása olvasásra. */
	/** Let's initialize the file stream for reading. */
	ifstream	fileStream(filePath, ios::in);
	string		content;
	string		line;

	/** A shader fájl sorainak beolvasása EOF jelzésig. (EOF = End Of File) */
	/** Read in the lines of the shader file until EOF. (EOF = End Of File) */
	while (!fileStream.eof()) {
		getline(fileStream, line);
		/** A shader fájl sorainak összefûzése. */
		/** Append the lines of the shader file. */
		content.append(line + "\n");
	}

	/** A file stream lezárása. */
	/** Let's close the file stream. */
	fileStream.close();

	/** Visszatérés a shader fájl tartalmával. */
	/** Return the content of the shader file. */
	return content;
}

GLuint createShaderProgram() {
	GLint		vertCompiled;
	GLint		fragCompiled;
	GLint		linked;
	/** Beolvassuk a shader fájlok tartalmát. */
	/** Read in both shader files. */
	string		vertShaderStr = readShaderSource("vertexShader.glsl");
	string		fragShaderStr = readShaderSource("fragmentShader.glsl");
	/** Létrehozzuk a shader objektumokat és eltároljuk az ID-ket. */
	/** Let's create the shader objects and store the IDs. */
	GLuint		vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint		fShader = glCreateShader(GL_FRAGMENT_SHADER);
	/** A shader fájlok tartalmát eltároló string objektum szöveggé konvertálásás is elvégezzük. */
	/** The contents of the shader string objects shall be converted to text of characters. */
	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();

	/** Ekkor a betöltött kódot hozzárendelhetjük a shader objektumainkhoz. */
	/** The loaded source codes are assigned to the shader objects. */
	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);

	/** Fordítsuk le a vertex shader objektumhoz rendelt kódot. */
	/** Let's compile the code of the vertex shader object. */
	glCompileShader(vShader);
	/** Hibakeresési lépések. Például sikeres volt-e a fordítás? Ha nem, mi volt az oka? */
	/** Error checking. Was the compile step successful? If not, what was the reason? */
	checkOpenGLError();
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
	if (vertCompiled != 1) {
		cout << "Vertex compilation failed." << endl;
		printShaderLog(vShader);
	}

	/** Fordítsuk le a fragment shader objektumhoz rendelt kódot. */
	/** Let's compile the code of the fragment shader object. */
	glCompileShader(fShader);
	/** Hibakeresési lépések. Például sikeres volt-e a fordítás? Ha nem, mi volt az oka? */
	/** Error checking. Was the compile step successful? If not, what was the reason? */
	checkOpenGLError();
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
	if (fragCompiled != 1) {
		cout << "Fragment compilation failed." << endl;
		printShaderLog(fShader);
	}

	/** Shader program objektum létrehozása: ez fogja össze a shadereket. Eltároljuk az ID értéket. */
	/** Shader program object initialization: holds together the shaders. vfProgram stores the ID. */
	GLuint		vfProgram = glCreateProgram();
	/** Csatoljuk a shadereket az elõzõ lépésben létrehozott objektumhoz. */
	/** The shaders are attached to the program object. */
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);

	/** Végül a GLSL szerkesztõ ellenõrzi, hogy a csatolt shaderek kompatibilisek-e egymással. */
	/** GLSL linker checks the shaders for compatibility. */
	glLinkProgram(vfProgram);
	/** Hibakeresési lépések. Például sikeres volt-e az összeszerkesztés? Ha nem, mi volt az oka? */
	/** Error checking. Was the link step successful? If not, what was the reason? */
	checkOpenGLError();
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
	if (linked != 1) {
		cout << "Shader linking failed." << endl;
		printProgramLog(vfProgram);
	}

	/** Ha minden rendben ment a linkelés során, a shader objektumok törölhetõek. */
	/** If everything is OK at linking, the shader objects can be destroyed. */
	glDeleteShader(vShader);
	glDeleteShader(fShader);

	/** Az elkészült program azonosítója a visszatérési értékünk. */
	/** The program ID will be the return value. */
	return vfProgram;
}

/*
N alatt R kiszámolása a lehetséges átrendezéses optimalizációval.
*/
/*
The definition of N choose R is to compute the two products and divide one with the other,
(N * (N - 1) * (N - 2) * ... * (N - R + 1)) / (1 * 2 * 3 * ... * R)
However, the multiplications may become too large really quick and overflow existing data type.
The implementation trick is to reorder the multiplicationand divisions as,
(N) / 1 * (N - 1) / 2 * (N - 2) / 3 * ... * (N - R + 1) / R
It's guaranteed that at each step the results is divisible 
(for n continuous numbers, one of them must be divisible by n, so is the product of these numbers).
For example, for N choose 3, at least one of the N, N - 1, N - 2 will be a multiple of 3, 
and for N choose 4, at least one of N, N - 1, N - 2, N - 3 will be a multiple of 4.
*/
long double NCR(int n, int r) {
/* Binomiális együttható. */
/* Binomial coefficient. */
	if (r == 0) return 1;

	/*
	 Extra computation saving for large R, using property:
	 N choose R = N choose (N - R)
	*/
	if (r > n / 2) return NCR(n, n - r);

	long double result = 1;

	for (int k = 1; k <= r; ++k) {
		result *= n - k + 1;
		result /= k;
	}

	return result;
}

/*
It will be the Bernstein basis polynomial of degree n.
*/
GLfloat blending(GLint n, GLint i, GLfloat t) {
	return NCR(n, i) * pow(t, i) * pow(1.0f - t, n - i);
}

void drawBezierCurve(std::vector<glm::vec3> controlPoints) {
/*
https://en.wikipedia.org/wiki/B%C3%A9zier_curve#Explicit_definition
https://hu.wikipedia.org/wiki/B%C3%A9zier-g%C3%B6rbe
*/
	glm::vec3	nextPoint;
	GLfloat		t = 0.0f;// , B;
	GLfloat		increment = 1.0f / 100.0f; /* hány darab szakaszból rakjuk össze a görbénket? */

	while (t <= 1.0f) {
		nextPoint = glm::vec3(0.0f, 0.0f, 0.0f);
		for (int i = 0; i < controlPoints.size(); i++) {
			//B = blending(controlPoints.size() - 1, i, t);
			nextPoint += blending(controlPoints.size() - 1, i, t) * controlPoints[i];
			//nextPoint.x += B * controlPoints.at(i).x;
			//nextPoint.y += B * controlPoints.at(i).y;
			//nextPoint.z += B * controlPoints.at(i).z;
		}

		pointToDraw.push_back(nextPoint);
		t += increment;
	}
}

void init(GLFWwindow* window) {
	/** A rajzoláshoz használt shader programok betöltése. */
	/** Loading the shader programs for rendering. */
	renderingProgram = createShaderProgram();

	/* A megadott paraméterû Bezier göbe pontjainak meghatározása. */
	/* Determining the points of the Bezier curve of the given parameters. */
	drawBezierCurve(myControlPoints);

	/* Létrehozzuk a szükséges vertex buffer és vertex array objektumokat. */
	/* Create the vertex buffer and vertex array objects. */
	glGenBuffers(numVBOs, VBO);
	glGenVertexArrays(numVAOs, VAO);

	/* A GL_ARRAY_BUFFER nevesített csatolóponthoz kapcsoljuk a vertex buffert (ide kerülnek a csúcspont adatok). */
	/* We attach the vertex buffer to the GL_ARRAY_BUFFER node (vertices are stored here). */
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);

	/* Másoljuk az adatokat a bufferbe! Megadjuk az aktuálisan csatolt buffert, azt hogy hány byte adatot másolunk,
	a másolandó adatot, majd a feldolgozás módját is meghatározzuk: most az adat nem változik a feltöltés után. */
	/* Copy the data to the buffer! First parameter is the currently attached buffer, second is the size of the buffer to be copied,
	third is the array of data, fourth is working mode: now the data can not be modified after this step. */
	glBufferData(GL_ARRAY_BUFFER, pointToDraw.size() * sizeof(glm::vec3), pointToDraw.data(), GL_STATIC_DRAW);

	/* Csatoljuk a vertex array objektumunkat a shader programhoz. */
	/* Attach the vertex array object to the shader program. */
	glBindVertexArray(VAO[0]);
	/* Ezen adatok szolgálják a location = 0 vertex attribútumot (itt: pozíció).
	   Elsõként megadjuk ezt az azonosítószámot (vertexShader.glsl).
	   Utána az attribútum méretét (vec3, láttuk a shaderben).
	   Harmadik az adat típusa.
	   Negyedik az adat normalizálása, ez maradhat FALSE jelen példában.
	   Az attribútum értékek hogyan következnek egymás után? Milyen lépésköz után találom a következõ vertex adatait?
	   Végül megadom azt, hogy honnan kezdõdnek az értékek a pufferben. Most rögtön, a legelejétõl veszem õket. */
	/* These values are for location = 0 vertex attribute (position).
		First is the location (vertexShader.glsl).
		Second is attribute size (vec3, as in the shader).
		Third is the data type.
		Fourth defines whether data shall be normalized or not, this is FALSE for the examples of the course.
		Fifth is the distance in bytes to the next vertex element of the array.
		Last is the offset of the first vertex data of the buffer. Now it is the start of the array. */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	/* Engedélyezzük az imént definiált location = 0 attribútumot (vertexShader.glsl). */
	/* Enable the previously defined location = 0 attributum (vertexShader.glsl). */
	glEnableVertexAttribArray(0);

	/* Leválasztjuk a vertex array objektumot és a buffert is. */
	/* Detach the vertex array object and the buffer also. */
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/** Aktiváljuk a shader-program objektumunkat az alapértelmezett fix csõvezeték helyett. */
	/** Activate our shader-program object instead of the default fix pipeline. */
	glUseProgram(renderingProgram);

	/** Ha pontokat vagy szakaszokat rajzolunk, kísérletezzünk a pont vagy szakasz méretének növelésével! */
	/** When drawing points or lines, we can make experiments with different point or line sizes! */
	glPointSize(10.0f);
	glLineWidth(5.0f);

	/** Állítsuk be a törlési színt az áttetszõségi értékkel együtt! [0.0, 1.0] */
	/** Set the clear color (red, green, blue, alpha), where alpha is transparency! [0.0, 1.0] */
	glClearColor(0.0, 0.0, 0.0, 1.0);

	cout << "float\t\t\t" << sizeof(float) << "\n";
	cout << "double\t\t\t" << sizeof(double) << "\n";
	cout << "long double\t\t" << sizeof(long double) << "\n";
	cout << "unsigned\t\t" << sizeof(unsigned) << "\n";
	cout << "long unsigned\t\t" << sizeof(long unsigned) << "\n";
	cout << "long long unsigned\t" << sizeof(long long unsigned) << "\n";
	
 // test for the NCR function
	for (int j = 0; j < 10; j++) {
		cout << j << "\n";
		for (int i = 0; i <= j; i++)
			cout << i << " " << NCR(j, i) << "  ";
		cout << "\n";
	}
}

void display(GLFWwindow* window, double currentTime) {
	/* Töröljük le a kiválasztott buffereket! Fontos lehet minden egyes alkalommal törölni! */
	/* Let's clear the selected buffers! Usually importand to clear it each time! */
	glClear(GL_COLOR_BUFFER_BIT);

	/* Csatoljuk fel a vertex array objektumot a shader programhoz. */
	/* Bind vertex array object to the shader program. */
	glBindVertexArray(VAO[0]);

	/** A megadott adatok segítségével megrajzoljuk a görbét. */
	/** We draw a curve with the defined array. */
	glDrawArrays(GL_LINE_STRIP, 0, pointToDraw.size());

	/* Leválasztjuk a VAO-t, nehogy bármilyen érték felülíródjon. */
	/* Detach VAO for safety reasons, not to modify it accidentaly. */
	glBindVertexArray(0);
}

/** Felesleges objektumok törlése. */
/** Clenup the unnecessary objects. */
void cleanUpScene() {
	/** Töröljük a vertex array és a vertex buffer objektumokat. */
	/** Destroy the vertex array and vertex buffer objects. */
	glDeleteVertexArrays(numVAOs, VAO);
	glDeleteBuffers(numVBOs, VBO);
	/** Töröljük a shader programot. */
	/** Let's delete the shader program. */
	glDeleteProgram(renderingProgram);
	/** Töröljük a GLFW ablakot. */
	/** Destroy the GLFW window. */
	glfwDestroyWindow(window);
	/** Leállítjuk a GLFW-t. */
	/** Stop the GLFW system. */
	glfwTerminate();
	/** Kilépés EXIT_SUCCESS kóddal. */
	/** Stop the software and exit with EXIT_SUCCESS code. */
	exit(EXIT_SUCCESS);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	window_width = width;
	window_height = height;

	/** A kezelt képernyõ beállítása a teljes (0, 0, width, height) területre. */
	/** Set the viewport for the full (0, 0, width, height) area. */
	glViewport(0, 0, width, height);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	/** ESC billentyûre kilépés. */
	/** Exit on ESC key. */
	if ((action == GLFW_PRESS) && (key == GLFW_KEY_ESCAPE))
		cleanUpScene();

	/** A billentyûk lenyomásának és felengedésének regisztrálása. Lehetõvé teszi gombkombinációk használatát. */
	/** Let's register press and release events for keys. Enables the usage of key combinations. */
	if (action == GLFW_PRESS)
		keyboard[key] = GL_TRUE;
	else if (action == GLFW_RELEASE)
		keyboard[key] = GL_FALSE;
}

void cursorPosCallback(GLFWwindow* window, double xPos, double yPos) {
	/** Az egér mutató helyét kezelõ függvény. */
	/** Callback function for mouse position change. */
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	/** Az egér gombjaihoz köthetõ események kezelése. */
	/** Callback function for mouse button events. */
}

int main(void) {
	/** Próbáljuk meg inicializálni a GLFW-t! */
	/** Try to initialize GLFW! */
	if (!glfwInit())
		exit(EXIT_FAILURE);

	/** A használni kívánt OpenGL verzió: 4.3. */
	/** The needed OpenGL version: 4.3. */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make macOS happy; should not be needed.
	/** Próbáljuk meg létrehozni az ablakunkat. */
	/** Let's try to create a window for drawing. */
	/** GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor * monitor, GLFWwindow * share) */
	window = glfwCreateWindow(window_width, window_height, window_title, nullptr, nullptr);

	/** Válasszuk ki az ablakunk OpenGL kontextusát, hogy használhassuk. */
	/** Select the OpenGL context (window) for drawing. */
	glfwMakeContextCurrent(window);

	/** A képernyõ átméretezés kezelése. */
	/** Callback function for window size change. */
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	/** Billentyûzethez köthetõ események kezelése. */
	/** Callback function for keyboard events. */
	glfwSetKeyCallback(window, keyCallback);
	/** Az egér mutató helyét kezelõ függvény megadása. */
	/** Callback function for mouse position change. */
	glfwSetCursorPosCallback(window, cursorPosCallback);
	/** Az egér gombjaihoz köthetõ események kezelése. */
	/** Callback function for mouse button events. */
	glfwSetMouseButtonCallback(window, mouseButtonCallback);

	/** Incializáljuk a GLEW-t, hogy elérhetõvé váljanak az OpenGL függvények, probléma esetén kilépés EXIT_FAILURE értékkel. */
	/** Initalize GLEW, so the OpenGL functions will be available, on problem exit with EXIT_FAILURE code. */
	if (glewInit() != GLEW_OK)
		exit(EXIT_FAILURE);

	/** 0 = v-sync kikapcsolva, 1 = v-sync bekapcsolva, n = n db képkockányi idõt várakozunk */
	/** 0 = v-sync off, 1 = v-sync on, n = n pieces frame time waiting */
	glfwSwapInterval(1);

	/** A window ablak minimum és maximum szélességének és magasságának beállítása. */
	/** The minimum and maximum width and height values of the window object. */
	glfwSetWindowSizeLimits(window, 400, 400, 800, 800);
	/** A window oldalarányának megadása a számláló és az osztó segítségével. */
	/** Setting the aspect ratio using the numerator and the denominator values. */
	glfwSetWindowAspectRatio(window, 1, 1);

	/** Az alkalmazáshoz kapcsolódó elõkészítõ lépések, pl. a shader objektumok létrehozása. */
	/** The first initialization steps of the program, e.g.: creating the shader objects. */
	init(window);

	/** A megadott window struktúra "close flag" vizsgálata. */
	/** Checks the "close flag" of the specified window. */
	while (!glfwWindowShouldClose(window)) {
		/** A kód, amellyel rajzolni tudunk a GLFWwindow objektumunkba. */
		/** Call display function which will draw into the GLFWwindow object. */
		display(window, glfwGetTime());
		/** Double buffered mûködés. */
		/** Double buffered working = swap the front and back buffer here. */
		glfwSwapBuffers(window);
		/** Események kezelése az ablakunkkal kapcsolatban, pl. gombnyomás. */
		/** Handle events related to our window, e.g.: pressing a key or moving the mouse. */
		glfwPollEvents();
	}

	/** Felesleges objektumok törlése. */
	/** Clenup the unnecessary objects. */
	cleanUpScene();

	/** Kilépés EXIT_SUCCESS kóddal. */
	/** Stop the software and exit with EXIT_SUCCESS code. */
	return EXIT_SUCCESS;
}