#ifndef FAGL_KEYBOARD_H
#define FAGL_KEYBOARD_H

#include "FAGL.h"

namespace fagl {
	bool* key_held_down;
	void (*HoldKeyAction)(int);
	void (*PressedKeyAction)(int);
	void (*ReleasedKeyAction)(int);

	void KeyPressed(int key) {
		key_held_down[key] = true;
		PressedKeyAction(key);
	}

	void KeyReleased(int key) {
		key_held_down[key] = false;
		ReleasedKeyAction(key);
	}

	void ParseKeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (action == GLFW_PRESS) {
			KeyPressed(key);
		}
		else if (action == GLFW_RELEASE) {
			KeyReleased(key);
		}
	}

	/// <summary>
	/// Parses currently held keys. Should be called once a frame.
	/// </summary>
	void ParseHoldKeys() {
		for (unsigned int i = 0; i <= GLFW_KEY_LAST; i++) {
			if (key_held_down[i])
				HoldKeyAction(i);
		}
	}

	/// <summary>
	/// Sets the keyboard response of the window.
	/// </summary>
	/// <param name="window"> The window whose keyboard response will be set.</param>
	/// <param name="hold"> The function to be called when a key is hold.</param>
	/// <param name="press"> The function to be called when a key is pressed.</param>
	/// <param name="release"> The function to be called when a key is released.</param>
	void InitKeyboard(GLFWwindow* window, void (*hold)(int), void (*press)(int), void (*release)(int)) {
		HoldKeyAction = hold;
		PressedKeyAction = press;
		ReleasedKeyAction = release;
		key_held_down = new bool[GLFW_KEY_LAST + 1];
		for (unsigned int i = 0; i <= GLFW_KEY_LAST; i++) {
			key_held_down[i] = false;
		}
		glfwSetKeyCallback(window, ParseKeyboardEvent);
	}
}


#endif
