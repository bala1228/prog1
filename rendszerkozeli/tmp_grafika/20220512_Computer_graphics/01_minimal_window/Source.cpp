#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


int			window_width	= 600;
int			window_height	= 600;
char		window_title[]	= "Hello OpenGL!";
GLFWwindow	*window			= nullptr;


/** Az alkalmaz�shoz kapcsol�d� el�k�sz�t� l�p�sek, pl. a shader objektumok l�trehoz�sa. */
/** The first initialization steps of the program, e.g.: creating the shader objects. */
void init() {
	/** T�rl�si sz�n be�ll�t�sa pirosra 1.0 �ttetsz�s�g mellett. (red, green, blue, alpha) [0.0, 1.0] */
	/** Set the clearing color for red at 1.0 transparency. (red, green, blue, alpha) [0.0, 1.0] */
	glClearColor(1.0, 0.0, 0.0, 1.0);
}

/** A k�d, amellyel rajzolni tudunk a GLFWwindow objektumunkba. */
/** Call display function which will draw into the GLFWwindow object. */
void display() {
	/** T�r�lj�k le a sz�nbuffert! */
	/** Let's clear the color buffer! */
	glClear(GL_COLOR_BUFFER_BIT);
}

/** Felesleges objektumok t�rl�se. */
/** Clenup the unnecessary objects. */
void cleanUpScene() {
	/** T�r�lj�k a GLFW ablakot. */
	/** Destroy the GLFW window. */
	glfwDestroyWindow(window);
	/** Le�ll�tjuk a GLFW-t. */
	/** Stop the GLFW system. */
	glfwTerminate();
	/** Kil�p�s EXIT_SUCCESS k�ddal. */
	/** Stop the software and exit with EXIT_SUCCESS code. */
	exit(EXIT_SUCCESS);
}

int main(void) {
	/** Pr�b�ljuk meg inicializ�lni a GLFW-t! */
	/** Try to initialize GLFW! */
	if (!glfwInit())
		exit(EXIT_FAILURE);

	/** A haszn�lni k�v�nt OpenGL verzi�: 4.3. */
	/** The needed OpenGL version: 4.3. */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#ifdef __APPLE__ // To make macOS happy; should not be needed.
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	/** Pr�b�ljuk meg l�trehozni az ablakunkat. */
	/** Let's try to create a window for drawing. */
	/** GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor * monitor, GLFWwindow * share) */
	window = glfwCreateWindow(window_width, window_height, window_title, nullptr, nullptr);

	/** V�lasszuk ki az ablakunk OpenGL kontextus�t, hogy haszn�lhassuk. */
	/** Select the OpenGL context (window) for drawing. */
	glfwMakeContextCurrent(window);

	/** Incializ�ljuk a GLEW-t, hogy el�rhet�v� v�ljanak az OpenGL f�ggv�nyek, probl�ma eset�n kil�p�s EXIT_FAILURE �rt�kkel. */
	/** Initalize GLEW, so the OpenGL functions will be available, on problem exit with EXIT_FAILURE code. */
	if (glewInit() != GLEW_OK)
		exit(EXIT_FAILURE);

	/** 0 = v-sync kikapcsolva, 1 = v-sync bekapcsolva, n = n db k�pkock�nyi id�t v�rakozunk */
	/** 0 = v-sync off, 1 = v-sync on, n = n pieces frame time waiting */
	glfwSwapInterval(1);
	/** Az alkalmaz�shoz kapcsol�d� el�k�sz�t� l�p�sek, pl. a shader objektumok l�trehoz�sa. */
	/** The first initialization steps of the program, e.g.: creating the shader objects. */
	init();

	/** A megadott window strukt�ra "close flag" vizsg�lata. */
	/** Checks the "close flag" of the specified window. */
	while (!glfwWindowShouldClose(window)) {
		/** A k�d, amellyel rajzolni tudunk a GLFWwindow objektumunkba. */
		/** Call display function which will draw into the GLFWwindow object. */
		display();
		/** Double buffered m�k�d�s. */
		/** Double buffered working = swap the front and back buffer here. */
		glfwSwapBuffers(window);
		/** Esem�nyek kezel�se az ablakunkkal kapcsolatban, pl. gombnyom�s. */
		/** Handle events related to our window, e.g.: pressing a key or moving the mouse. */
		glfwPollEvents();
	}

	/** Felesleges objektumok t�rl�se. */
	/** Clenup the unnecessary objects. */
	cleanUpScene();

	/** Kil�p�s EXIT_SUCCESS k�ddal. */
	/** Stop the software and exit with EXIT_SUCCESS code. */
	return EXIT_SUCCESS;
}