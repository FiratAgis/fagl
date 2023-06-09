#ifndef FAGL_PROGRAM_H
#define FAGL_PROGRAM_H

#include "CommonInclude.h"

namespace fagl {

	/// <summary>
	/// Reads the contents of a shader file.
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="data"></param>
	/// <returns> Whether reading was successful or not.</returns>
	bool ReadDataFromFile(const std::string& fileName, std::string& data);

	/// <summary>
	/// Reads shader file.
	/// </summary>
	/// <param name="shaderName"> Name of the shader file.</param>
	/// <param name="shaderType"> Type of the shader file.</param>
	/// <returns> Pointer to the read shader.</returns>
	GLuint CreateShader(const std::string shaderName, GLenum shaderType);

	/// <summary>
	/// Creates a program and binds given shaders to it.
	/// </summary>
	/// <param name="vs"> Path of the vertex shader.</param>
	/// <param name="tcs"> Path of the tessellation control shader.</param>
	/// <param name="tes"> Path of the tessellation evaluation shader.</param>
	/// <param name="gs"> Path of the geometry shader.</param>
	/// <param name="fs"> Path of the fragment shader.</param>
	/// <returns> Pointer to the program.</returns>
	GLuint CreateProgram(const std::string vs = std::string(""), const std::string tcs = std::string(""), const std::string tes = std::string(""), const std::string gs = std::string(""), const std::string fs = std::string(""));
}

#include "Program.inl"

#endif