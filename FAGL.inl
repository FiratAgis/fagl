#include "FAGL.h"

namespace fagl {
	void faglEnable(ENABLE_CAPABILITY cap)
	{
		glEnable((GLenum)cap);
	}

	void faglDisable(ENABLE_CAPABILITY cap)
	{
		glDisable((GLenum)cap);
	}

	void faglEnablei(ENABLE_CAPABILITY cap, GLuint index)
	{
		glEnablei((GLenum)cap, index);
	}

	void faglDisablei(ENABLE_CAPABILITY cap, GLuint index)
	{
		glDisablei((GLenum)cap, index);
	}

	GLboolean faglIsEnabled(ENABLE_CAPABILITY cap)
	{
		return glIsEnabled((GLenum)cap);
	}

	GLboolean faglIsEnabledi(ENABLE_CAPABILITY cap, GLuint index)
	{
		return glIsEnabledi((GLenum)cap, index);
	}

	void faglGenBuffers(GLsizei n, FAGLbuffer* buffers)
	{
		glGenBuffers(n, buffers);
	}

	void faglGenBuffer(FAGLbuffer* buffer)
	{
		glGenBuffers(1, buffer);
	}

	void faglBindBuffer(BIND_BUFFER_TARGET target, FAGLbuffer buffer)
	{
		glBindBuffer((GLenum)target, buffer);
	}

	void faglBufferData(BIND_BUFFER_TARGET target, GLsizeiptr size, const void* data, BUFFER_DATA_USAGE usage)
	{
		glBufferData((GLenum)target, size, data, (GLenum)usage);
	}

	void faglNamedBufferData(FAGLbuffer buffer, GLsizeiptr size, const void* data, BUFFER_DATA_USAGE usage)
	{
		glNamedBufferData(buffer, size, data, (GLenum)usage);
	}

	void faglGenTextures(GLsizei n, FAGLtexture* textures)
	{
		glGenTextures(n, textures);
	}

	void faglGenTexture(FAGLtexture* texture)
	{
		glGenTextures(1, texture);
	}

	void faglGenFramebuffers(GLsizei n, FAGLframebuffer* ids)
	{
		glGenFramebuffers(n, ids);
	}

	void faglGenFramebuffer(FAGLframebuffer* id)
	{
		glGenFramebuffers(1, id);
	}

	void faglBindFramebuffer(BIND_FRAMEBUFFER_TARGET target, FAGLframebuffer framebuffer)
	{
		glBindFramebuffer((GLenum)target, framebuffer);
	}

	void faglBindFramebuffer(FAGLframebuffer framebuffer)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	}

	void faglUnbindFramebuffer()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void faglGenRenderbuffers(GLsizei n, FAGLrenderbuffer* renderbuffers)
	{
		glGenRenderbuffers(n, renderbuffers);
	}

	void faglGenRenderbuffer(FAGLrenderbuffer* renderbuffer)
	{
		glGenRenderbuffers(1, renderbuffer);
	}

	void faglBindRenderbuffer(FAGLrenderbuffer renderbuffer)
	{
		glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
	}

	void faglUnbindRenderbuffer()
	{
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}

	void faglTexImage3D(TEXTURE_IMAGE_3D_TARGET target, GLint level, TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, GLsizei width, GLsizei height, GLsizei depth, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* data)
	{
		glTexImage3D((GLenum)target, level, (GLint)internalformat, width, height, depth, 0, (GLenum)format, (GLenum)type, data);
	}

	void faglTexImage2D(TEXTURE_IMAGE_2D_TARGET target, GLint level, TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, GLsizei width, GLsizei height, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* data)
	{
		glTexImage2D((GLenum)target, level, (GLint)internalformat, width, height, 0, (GLenum)format, (GLenum)type, data);
	}

	void faglTexImage1D(TEXTURE_IMAGE_1D_TARGET target, GLint level, TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, GLsizei width, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* data)
	{
		glTexImage1D((GLenum)target, level, (GLint)internalformat, width, 0, (GLenum)format, (GLenum)type, data);
	}

	void faglTexSubImage3D(TEXTURE_SUB_3D_TARGET target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTexSubImage3D((GLenum)target, level, xoffset, yoffset, zoffset, width, height, depth, (GLenum)format, (GLenum)type, pixels);
	}

	void faglTextureSubImage3D(FAGLtexture texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, (GLenum)format, (GLenum)type, pixels);
	}

	void faglTexSubImage2D(TEXTURE_SUB_2D_TARGET target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTexSubImage2D((GLenum)target, level, xoffset, yoffset, width, height, (GLenum)format, (GLenum)type, pixels);
	}

	void faglTextureSubImage2D(FAGLtexture texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, (GLenum)format, (GLenum)type, pixels);
	}

	void faglTexSubImage1D(GLint level, GLint xoffset, GLsizei width, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, (GLenum)format, (GLenum)type, pixels);
	}

	void faglTextureSubImage1D(FAGLtexture texture, GLint level, GLint xoffset, GLsizei width, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTextureSubImage1D(texture, level, xoffset, width, (GLenum)format, (GLenum)type, pixels);
	}

	void faglBindTexture(BIND_TEXTURE_TARGET target, FAGLtexture texture)
	{
		glBindTexture((GLenum)target, texture);
	}

	void faglTexParameterf(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, GLfloat param)
	{
		glTexParameterf((GLenum)target, (GLenum)pname, param);
	}

	void faglTexParameteri(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, GLint param)
	{
		glTexParameteri((GLenum)target, (GLenum)pname, param);
	}

	void faglTextureParameterf(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, GLfloat param)
	{
		glTextureParameterf(texture, (GLenum)pname, param);
	}

	void faglTextureParameteri(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, GLint param)
	{
		glTextureParameteri(texture, (GLenum)pname, param);
	}

	void faglTexParameterfv(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, const GLfloat* params)
	{
		glTexParameterfv((GLenum)target, (GLenum)pname, params);
	}

	void faglTexParameteriv(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTexParameteriv((GLenum)target, (GLenum)pname, params);
	}

	void faglTexParameterIiv(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTexParameterIiv((GLenum)target, (GLenum)pname, params);
	}

	void faglTexParameterIuiv(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, const GLuint* params)
	{
		glTexParameterIuiv((GLenum)target, (GLenum)pname, params);
	}

	void faglTextureParameterfv(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, const GLfloat* params)
	{
		glTextureParameterfv(texture, (GLenum)pname, params);
	}

	void faglTextureParameteriv(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTextureParameteriv(texture, (GLenum)pname, params);
	}

	void faglTextureParameterIiv(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTextureParameterIiv(texture, (GLenum)pname, params);
	}

	void faglTextureParameterIuiv(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, const GLuint* params)
	{
		glTextureParameterIuiv(texture, (GLenum)pname, params);
	}

	void faglPixelStoref(PIXEL_STORE_NAME pname, GLfloat param)
	{
		glPixelStoref((GLenum)pname, param);
	}

	void faglPixelStorei(PIXEL_STORE_NAME pname, GLint param)
	{
		glPixelStorei((GLenum)pname, param);
	}

	void faglGenerateMipmap(MIPMAP_TARGET target)
	{
		glGenerateMipmap((GLenum)target);
	}

	void faglGenerateTextureMipmap(FAGLtexture texture)
	{
		glGenerateTextureMipmap(texture);
	}
	FAGLprogram faglCreateProgram()
	{
		return glCreateProgram();
	}
	void faglUseProgram(FAGLprogram program)
	{
		glUseProgram(program);
	}
	void faglLinkProgram(FAGLprogram program)
	{
		glLinkProgram(program);
	}
	FAGLshader faglCreateShader(CREATE_SHADER_TYPE shaderType)
	{
		return glCreateShader((GLenum)shaderType);
	}
	void faglShaderSource(FAGLshader shader, GLsizei count, const GLchar** string, const GLint* length)
	{
		glShaderSource(shader, count, string, length);
	}
	void faglCompileShader(FAGLshader shader)
	{
		glCompileShader(shader);
	}
	void faglGetShaderInfoLog(FAGLshader shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog)
	{
		glGetShaderInfoLog(shader, maxLength, length, infoLog);
	}
	void faglReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, READ_PIXEL_FORMAT format, READ_PIXEL_TYPE type, void* data)
	{
		glReadPixels(x, y, width, height, (GLenum)format, (GLenum)type, data);
	}
	void faglReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, READ_PIXEL_FORMAT format, READ_PIXEL_TYPE type, GLsizei bufSize, void* data)
	{
		glReadnPixels(x, y, width, height, (GLenum)format, (GLenum)type, bufSize, data);
	}
	void faglReadPixels(GLsizei width, GLsizei height, READ_PIXEL_FORMAT format, READ_PIXEL_TYPE type, void* data)
	{
		glReadPixels(0, 0, width, height, (GLenum)format, (GLenum)type, data);
	}
	void faglReadnPixels(GLsizei width, GLsizei height, READ_PIXEL_FORMAT format, READ_PIXEL_TYPE type, GLsizei bufSize, void* data)
	{
		glReadnPixels(0, 0, width, height, (GLenum)format, (GLenum)type, bufSize, data);
	}

	FAGLuniform faglGetUniformLocation(FAGLprogram program, const GLchar* name)
	{
		return glGetUniformLocation(program, name);
	}

	FAGLuniform faglGetUniformLocation(const GLchar* name)
	{
		GLint program;
		faglGetIntegerv(GET_NAME::CURRENT_PROGRAM, &program);
		return glGetUniformLocation(program, name);
	}

	void faglGetBooleanv(GET_NAME pname, GLboolean* data)
	{
		glGetBooleanv((GLenum)pname, data);
	}

	void faglGetDoublev(GET_NAME pname, GLdouble* data)
	{
		glGetDoublev((GLenum)pname, data);
	}

	void faglGetFloatv(GET_NAME pname, GLfloat* data)
	{
		glGetFloatv((GLenum)pname, data);
	}

	void faglGetIntegerv(GET_NAME pname, GLint* data)
	{
		glGetIntegerv((GLenum)pname, data);
	}

	void faglGetInteger64v(GET_NAME pname, GLint64* data)
	{
		glGetInteger64v((GLenum)pname, data);
	}

	void faglGetBooleani_v(GET_NAME target, GLuint index, GLboolean* data)
	{
		glGetBooleani_v((GLenum)target, index, data);
	}

	void faglGetIntegeri_v(GET_NAME target, GLuint index, GLint* data)
	{
		glGetIntegeri_v((GLenum)target, index, data);
	}

	void faglGetFloati_v(GET_NAME target, GLuint index, GLfloat* data)
	{
		glGetFloati_v((GLenum)target, index, data);
	}

	void faglGetDoublei_v(GET_NAME target, GLuint index, GLdouble* data)
	{
		glGetDoublei_v((GLenum)target, index, data);
	}

	void faglGetInteger64i_v(GET_NAME target, GLuint index, GLint64* data)
	{
		glGetInteger64i_v((GLenum)target, index, data);
	}

	void faglGenVertexArrays(GLsizei n, FAGLvertexarrar* arrays) {
		glGenVertexArrays(n, arrays);
	}

	void faglGenVertexArray(FAGLvertexarrar* array) {
		glGenVertexArrays(1, array);
	}

	void faglBindVertexArray(FAGLvertexarrar array) {
		glBindVertexArray(array);
	}

	void faglUnbindVertexArray() {
		glBindVertexArray(0);
	}

	void faglVertexAttribPointer(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, BOOLEAN normalized, GLsizei stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, (GLenum)type, (GLboolean)normalized, stride, pointer);
	}

	void faglVertexAttribPointer(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, (GLenum)type, GL_FALSE, stride, pointer);
	}

	void faglVertexAttribIPointer(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glVertexAttribIPointer(index, size, (GLenum)type, stride, pointer);
	}

	void faglVertexAttribLPointer(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glVertexAttribLPointer(index, size, (GLenum)type, stride, pointer);
	}

	void faglVertexAttribPointerC(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, BOOLEAN normalized, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, (GLenum)type, (GLboolean)normalized, stride, pointer);
	}

	void faglVertexAttribPointerC(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, (GLenum)type, GL_FALSE, stride, pointer);
	}

	void faglVertexAttribIPointerC(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribIPointer(index, size, (GLenum)type, stride, pointer);
	}

	void faglVertexAttribLPointerC(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribLPointer(index, size, (GLenum)type, stride, pointer);
	}

	void faglDrawArrays(DRAW_MODE mode, GLint first, GLsizei count)
	{
		glDrawArrays((GLenum)mode, first, count);
	}

	void faglDrawArrays(DRAW_MODE mode, GLsizei count)
	{
		glDrawArrays((GLenum)mode, 0, count);
	}

	void faglDrawElements(DRAW_MODE mode, GLsizei count, DRAW_TYPE type, const void* indices)
	{
		glDrawElements((GLenum)mode, count, (GLenum)type, indices);
	}
	void faglAttachShader(FAGLprogram program, FAGLshader shader)
	{
		glAttachShader(program, shader);
	}
	void faglAttachShader(FAGLprogram program, GLuint count, FAGLshader* shaders)
	{
		for(GLuint i = 0; i < count; i++)
			glAttachShader(program, shaders[i]);
	}
	void faglAttachShader(FAGLprogram program, std::vector<FAGLshader> shaders)
	{
		for(GLuint shader : shaders)
			glAttachShader(program, shader);
	}
	void faglReadBuffer(READ_BUFFER_MODE mode)
	{
		glReadBuffer((GLenum)mode);
	}
	void faglNamedFramebufferReadBuffer(FAGLframebuffer framebuffer, READ_BUFFER_MODE mode)
	{
		glNamedFramebufferReadBuffer(framebuffer, (GLenum)mode);
	}
	void faglUniform1f(FAGLuniform location, GLfloat v0)
	{
		glUniform1f(location, v0);
	}
	void faglUniform2f(FAGLuniform location, GLfloat v0, GLfloat v1)
	{
		glUniform2f(location, v0, v1);
	}
	void faglUniform3f(FAGLuniform location, GLfloat v0, GLfloat v1, GLfloat v2)
	{
		glUniform3f(location, v0, v1, v2);
	}
	void faglUniform4f(FAGLuniform location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	{
		glUniform4f(location, v0, v1, v2, v3);
	}
	void faglUniform1i(FAGLuniform location, GLint v0)
	{
		glUniform1i(location, v0);
	}
	void faglUniform2i(FAGLuniform location, GLint v0, GLint v1)
	{
		glUniform2i(location, v0, v1);
	}
	void faglUniform3i(FAGLuniform location, GLint v0, GLint v1, GLint v2)
	{
		glUniform3i(location, v0, v1, v2);
	}
	void faglUniform4i(FAGLuniform location, GLint v0, GLint v1, GLint v2, GLint v3)
	{
		glUniform4i(location, v0, v1, v2, v3);
	}
	void faglUniform1ui(FAGLuniform location, GLuint v0)
	{
		glUniform1ui(location, v0);
	}
	void faglUniform2ui(FAGLuniform location, GLuint v0, GLuint v1)
	{
		glUniform2ui(location, v0, v1);
	}
	void faglUniform3ui(FAGLuniform location, GLuint v0, GLuint v1, GLuint v2)
	{
		glUniform3ui(location, v0, v1, v2);
	}
	void faglUniform4ui(FAGLuniform location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
	{
		glUniform4ui(location, v0, v1, v2, v3);
	}
	void faglUniform1fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniform1fv(location, count, value);
	}
	void faglUniform1fv(FAGLuniform location, const GLfloat* value)
	{
		glUniform1fv(location, 1, value);
	}
	void faglUniform2fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniform2fv(location, count, value);
	}
	void faglUniform2fv(FAGLuniform location, const GLfloat* value)
	{
		glUniform2fv(location, 1, value);
	}
	void faglUniform3fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniform3fv(location, count, value);
	}
	void faglUniform3fv(FAGLuniform location, const GLfloat* value)
	{
		glUniform3fv(location, 1, value);
	}
	void faglUniform4fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniform4fv(location, count, value);
	}
	void faglUniform4fv(FAGLuniform location, const GLfloat* value)
	{
		glUniform4fv(location, 1, value);
	}
	void faglUniform1iv(FAGLuniform location, GLsizei count, const GLint* value)
	{
		glUniform1iv(location, count, value);
	}
	void faglUniform1iv(FAGLuniform location, const GLint* value)
	{
		glUniform1iv(location, 1, value);
	}
	void faglUniform2iv(FAGLuniform location, GLsizei count, const GLint* value)
	{
		glUniform2iv(location, count, value);
	}
	void faglUniform2iv(FAGLuniform location, const GLint* value)
	{
		glUniform2iv(location, 1, value);
	}
	void faglUniform3iv(FAGLuniform location, GLsizei count, const GLint* value)
	{
		glUniform3iv(location, count, value);
	}
	void faglUniform3iv(FAGLuniform location, const GLint* value)
	{
		glUniform3iv(location, 1, value);
	}
	void faglUniform4iv(FAGLuniform location, GLsizei count, const GLint* value)
	{
		glUniform4iv(location, count, value);
	}
	void faglUniform4iv(FAGLuniform location, const GLint* value)
	{
		glUniform4iv(location, 1, value);
	}
	void faglUniform1uiv(FAGLuniform location, GLsizei count, const GLuint* value)
	{
		glUniform1uiv(location, count, value);
	}
	void faglUniform1uiv(FAGLuniform location, const GLuint* value)
	{
		glUniform1uiv(location, 1, value);
	}
	void faglUniform2uiv(FAGLuniform location, GLsizei count, const GLuint* value)
	{
		glUniform2uiv(location, count, value);
	}
	void faglUniform2uiv(FAGLuniform location, const GLuint* value)
	{
		glUniform2uiv(location, 1, value);
	}
	void faglUniform3uiv(FAGLuniform location, GLsizei count, const GLuint* value)
	{
		glUniform3uiv(location, count, value);
	}
	void faglUniform3uiv(FAGLuniform location, const GLuint* value)
	{
		glUniform3uiv(location, 1, value);
	}
	void faglUniform4uiv(FAGLuniform location, GLsizei count, const GLuint* value)
	{
		glUniform4uiv(location, count, value);
	}
	void faglUniform4uiv(FAGLuniform location, const GLuint* value)
	{
		glUniform4uiv(location, 1, value);
	}
	void faglUniformMatrix2fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2fv(location, count, (GLboolean)transpose, value);
	}
	void faglUniformMatrix2fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2fv(location, 1, (GLboolean)transpose, value);
	}
	void faglUniformMatrix2fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix2fv(location, count, GL_FALSE, value);
	}
	void faglUniformMatrix2fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix2fv(location, 1, GL_FALSE, value);
	}
	void faglUniformMatrix3fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3fv(location, count, (GLboolean)transpose, value);
	}
	void faglUniformMatrix3fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3fv(location, 1, (GLboolean)transpose, value);
	}
	void faglUniformMatrix3fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix3fv(location, count, GL_FALSE, value);
	}
	void faglUniformMatrix3fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix3fv(location, 1, GL_FALSE, value);
	}
	void faglUniformMatrix4fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4fv(location, count, (GLboolean)transpose, value);
	}
	void faglUniformMatrix4fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4fv(location, 1, (GLboolean)transpose, value);
	}
	void faglUniformMatrix4fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix4fv(location, count, GL_FALSE, value);
	}
	void faglUniformMatrix4fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, value);
	}
	void faglUniformMatrix2x3fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2x3fv(location, count, (GLboolean)transpose, value);
	}
	void faglUniformMatrix2x3fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2x3fv(location, 1, (GLboolean)transpose, value);
	}
	void faglUniformMatrix2x3fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix2x3fv(location, count, GL_FALSE, value);
	}
	void faglUniformMatrix2x3fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix2x3fv(location, 1, GL_FALSE, value);
	}
	void faglUniformMatrix3x2fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3x2fv(location, count, (GLboolean)transpose, value);
	}
	void faglUniformMatrix3x2fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3x2fv(location, 1, (GLboolean)transpose, value);
	}
	void faglUniformMatrix3x2fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix3x2fv(location, count, GL_FALSE, value);
	}
	void faglUniformMatrix3x2fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix3x2fv(location, 1, GL_FALSE, value);
	}
	void faglUniformMatrix2x4fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2x4fv(location, count, (GLboolean)transpose, value);
	}
	void faglUniformMatrix2x4fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2x4fv(location, 1, (GLboolean)transpose, value);
	}
	void faglUniformMatrix2x4fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix2x4fv(location, count, GL_FALSE, value);
	}
	void faglUniformMatrix2x4fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix2x4fv(location, 1, GL_FALSE, value);
	}
	void faglUniformMatrix4x2fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4x2fv(location, count, (GLboolean)transpose, value);
	}
	void faglUniformMatrix4x2fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4x2fv(location, 1, (GLboolean)transpose, value);
	}
	void faglUniformMatrix4x2fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix4x2fv(location, count, GL_FALSE, value);
	}
	void faglUniformMatrix4x2fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix4x2fv(location, 1, GL_FALSE, value);
	}
	void faglUniformMatrix3x4fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3x4fv(location, count, (GLboolean)transpose, value);
	}
	void faglUniformMatrix3x4fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3x4fv(location, 1, (GLboolean)transpose, value);
	}
	void faglUniformMatrix3x4fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix3x4fv(location, count, GL_FALSE, value);
	}
	void faglUniformMatrix3x4fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix3x4fv(location, 1, GL_FALSE, value);
	}
	void faglUniformMatrix4x3fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4x3fv(location, count, (GLboolean)transpose, value);
	}
	void faglUniformMatrix4x3fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4x3fv(location, 1, (GLboolean)transpose, value);
	}
	void faglUniformMatrix4x3fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix4x3fv(location, count, GL_FALSE, value);
	}
	void faglUniformMatrix4x3fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix4x3fv(location, 1, GL_FALSE, value);
	}
	void faglDepthFunc(DEPTH_FUNC func)
	{
		glDepthFunc((GLenum)func);
	}
	void faglBlendFunc(BLEND_FUNC sfactor, BLEND_FUNC dfactor)
	{
		glBlendFunc((GLenum)sfactor, (GLenum)dfactor);
	}
	void faglBlendFunci(GLuint buf, BLEND_FUNC sfactor, BLEND_FUNC dfactor)
	{
		glBlendFunci(buf, (GLenum)sfactor, (GLenum)dfactor);
	}
	void faglFramebufferTexture(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture((GLenum)target, (GLenum)attachment, texture, level);
	}
	void faglFramebufferTexture(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glFramebufferTexture((GLenum)target, (GLenum)attachment, texture, 0);
	}
	void faglFramebufferTexture(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture(GL_FRAMEBUFFER, (GLenum)attachment, texture, level);
	}
	void faglFramebufferTexture(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glFramebufferTexture(GL_FRAMEBUFFER, (GLenum)attachment, texture, 0);
	}
	void faglFramebufferTexture1D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture1D((GLenum)target, (GLenum)attachment, GL_TEXTURE_1D, texture, level);
	}
	void faglFramebufferTexture1D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glFramebufferTexture1D((GLenum)target, (GLenum)attachment, GL_TEXTURE_1D, texture, 0);
	}
	void faglFramebufferTexture1D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture1D(GL_FRAMEBUFFER, (GLenum)attachment, GL_TEXTURE_1D, texture, level);
	}
	void faglFramebufferTexture1D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glFramebufferTexture1D(GL_FRAMEBUFFER, (GLenum)attachment, GL_TEXTURE_1D, texture, 0);
	}
	void faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET textarget, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture2D((GLenum)target, (GLenum)attachment, (GLenum)textarget, texture, level);
	}
	void faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET textarget, FAGLtexture texture)
	{
		glFramebufferTexture2D((GLenum)target, (GLenum)attachment, (GLenum)textarget, texture, 0);
	}
	void faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET textarget, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture2D(GL_FRAMEBUFFER, (GLenum)attachment, (GLenum)textarget, texture, level);
	}
	void faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET textarget, FAGLtexture texture)
	{
		glFramebufferTexture2D(GL_FRAMEBUFFER, (GLenum)attachment, (GLenum)textarget, texture, 0);
	}
	void faglFramebufferTexture3D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level, GLint layer)
	{
		glFramebufferTexture3D((GLenum)target, (GLenum)attachment, GL_TEXTURE_3D, texture, level, layer);
	}
	void faglFramebufferTexture3D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint layer)
	{
		glFramebufferTexture3D((GLenum)target, (GLenum)attachment, GL_TEXTURE_3D, texture, 0, layer);
	}
	void faglFramebufferTexture3D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level, GLint layer)
	{
		glFramebufferTexture3D(GL_FRAMEBUFFER, (GLenum)attachment, GL_TEXTURE_3D, texture, level, layer);
	}
	void faglFramebufferTexture3D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint layer)
	{
		glFramebufferTexture3D(GL_FRAMEBUFFER, (GLenum)attachment, GL_TEXTURE_3D, texture, 0, layer);
	}
	void faglNamedFramebufferTexture(FAGLframebuffer framebuffer, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glNamedFramebufferTexture(framebuffer, (GLenum)attachment, texture, level);
	}
	void faglNamedFramebufferTexture(FAGLframebuffer framebuffer, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glNamedFramebufferTexture(framebuffer, (GLenum)attachment, texture, 0);
	}
}

