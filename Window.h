#ifndef FAGL_WINDOW_H
#define FAGL_WINDOW_H

#include "CommonInclude.h"

namespace fagl {
	/// <summary>
	/// Initializes glfw, creates a GLFWwindow, and sets window's size callback. Should be called first because this handles glfw initialization for all library
	/// </summary>
	/// <param name="width"> Width of the created window. </param>
	/// <param name="height"> Height of the created window. </param>
	/// <param name="wWrite"> Where width of the window will be written as it changes. </param>
	/// <param name="hWrite"> Where width of the window will be written as it changes. </param>
	/// <param name="pWrite"> Where projection matrix of the window will be written as it changes.</param>
	/// <returns> The created window </returns>
	GLFWwindow* InitilizeWindow(int width, int height, int *wWrite, int *hWrite, glm::mat4 *pWrite);

	/// <summary>
	/// Clears the current frame buffer.
	/// </summary>
	void ClearDisplay();

	/// <summary>
	/// The size callback function used by the library. Updates width, height and projection matrix if their pointer is set.
	/// </summary>
	/// <param name="window"> The window. </param>
	/// <param name="w"> New width of the window. </param>
	/// <param name="h"> New height of the window. </param>
	void Reshape(GLFWwindow* window, int w, int h);
}

#include "Window.inl"

#endif
