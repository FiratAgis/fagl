#include <cstring>
#include <glm/gtc/matrix_transform.hpp>
#include "Window.h"

#pragma warning(disable : 4996)

namespace fagl {
	int* wLoc;
	int* hLoc;
	glm::mat4* pLoc;

	GLFWwindow* InitilizeWindow(int width, int height, int* wWrite, int* hWrite, glm::mat4* pWrite)
	{
		GLFWwindow* window;
		wLoc = wWrite;
		hLoc = hWrite;
		pLoc = pWrite;

		if (wLoc != NULL)
			(*wLoc) = width;

		if (hLoc != NULL)
			(*hLoc) = height;

		if (!glfwInit())
		{
			exit(-1);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, "Simple Example", NULL, NULL);

		if (!window)
		{
			glfwTerminate();
			exit(-1);
		}

		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);

		if (GLEW_OK != glewInit())
		{
			std::cout << "Failed to initialize GLEW" << std::endl;
			exit(-1);
		}

		char rendererInfo[512] = { 0 };
		strcpy(rendererInfo, (const char*)glGetString(GL_RENDERER));
		strcat(rendererInfo, " - ");
		strcat(rendererInfo, (const char*)glGetString(GL_VERSION));
		glfwSetWindowTitle(window, rendererInfo);

		glfwSetWindowSizeCallback(window, Reshape);

		Reshape(window, width, height);

		return window;
	}

	void ClearDisplay()
	{
		glClearColor(0, 0, 0, 1);
		glClearDepth(1.0f);
		glClearStencil(0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void Reshape(GLFWwindow* window, int w, int h)
	{
		w = w < 1 ? 1 : w;
		h = h < 1 ? 1 : h;

		if (wLoc != NULL)
			*(wLoc) = w;
		if (hLoc != NULL)
			*(hLoc) = h;

		glViewport(0, 0, w, h);

		float fovyRad = (float)(45.0 / 180.0) * M_PI;
		if (pLoc != NULL)
			*(pLoc) = glm::perspective(fovyRad, ((GLfloat)w) / ((GLfloat)h), 1.0f, 100.0f);
	}
}