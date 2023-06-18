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

	void faglGenBuffers(GLsizei n, GLuint* buffers)
	{
		glGenBuffers(n, buffers);
	}

	void faglGenBuffer(GLuint* buffer)
	{
		glGenBuffers(1, buffer);
	}

	void faglBindBuffer(BIND_BUFFER_TARGET target, GLuint buffer)
	{
		glBindBuffer((GLenum)target, buffer);
	}

	void faglBufferData(BIND_BUFFER_TARGET target, GLsizeiptr size, const void* data, BUFFER_DATA_USAGE usage)
	{
		glBufferData((GLenum)target, size, data, (GLenum)usage);
	}

	void faglNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, BUFFER_DATA_USAGE usage)
	{
		glNamedBufferData(buffer, size, data, (GLenum)usage);
	}

	void faglGenTextures(GLsizei n, GLuint* textures)
	{
		glGenTextures(n, textures);
	}

	void faglGenTexture(GLuint* texture)
	{
		glGenTextures(1, texture);
	}

	void faglGenFramebuffers(GLsizei n, GLuint* ids)
	{
		glGenFramebuffers(n, ids);
	}

	void faglGenFramebuffer(GLuint* id)
	{
		glGenFramebuffers(1, id);
	}

	void faglBindFramebuffer(BIND_FRAMEBUFFER_TARGET target, GLuint framebuffer)
	{
		glBindFramebuffer((GLenum)target, framebuffer);
	}

	void faglBindFramebuffer(GLuint framebuffer)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	}

	void faglUnbindFramebuffer()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void faglGenRenderbuffers(GLsizei n, GLuint* renderbuffers)
	{
		glGenRenderbuffers(n, renderbuffers);
	}

	void faglGenRenderbuffer(GLuint* renderbuffer)
	{
		glGenRenderbuffers(1, renderbuffer);
	}

	void faglBindRenderbuffer(GLuint renderbuffer)
	{
		glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
	}

	void faglUnbindRenderbuffer()
	{
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}

	void faglTexImage2D(TEXTURE_IMAGE_2D_TARGET target, GLint level, TEXTURE_IMAGE_2D_INTERNAL_FORMAT internalformat, GLsizei width, GLsizei height, TEXTURE_IMAGE_2D_FORMAT format, TEXTURE_IMAGE_2D_TYPE type, const void* data)
	{
		glTexImage2D((GLenum)target, level, (GLint)internalformat, width, height, 0, (GLenum)format, (GLenum)type, data);
	}

	void faglBindTexture(BIND_TEXTURE_TARGET target, GLuint texture)
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

	void faglTextureParameterf(GLuint texture, TEXTURE_PARAMETER_NAME pname, GLfloat param)
	{
		glTextureParameterf(texture, (GLenum)pname, param);
	}

	void faglTextureParameteri(GLuint texture, TEXTURE_PARAMETER_NAME pname, GLint param)
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

	void faglTextureParameterfv(GLuint texture, TEXTURE_PARAMETER_NAME pname, const GLfloat* params)
	{
		glTextureParameterfv(texture, (GLenum)pname, params);
	}

	void faglTextureParameteriv(GLuint texture, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTextureParameteriv(texture, (GLenum)pname, params);
	}

	void faglTextureParameterIiv(GLuint texture, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTextureParameterIiv(texture, (GLenum)pname, params);
	}

	void faglTextureParameterIuiv(GLuint texture, TEXTURE_PARAMETER_NAME pname, const GLuint* params)
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

	void faglGenerateTextureMipmap(GLuint texture)
	{
		glGenerateTextureMipmap(texture);
	}
	GLuint faglCreateShader(CREATE_SHADER_TYPE shaderType)
	{
		glCreateShader((GLenum)shaderType);
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

	GLint faglGetUniformLocation(GLuint program, const GLchar* name)
	{
		glGetUniformLocation(program, name);
	}

	GLint faglGetUniformLocation(const GLchar* name)
	{
		GLint program;
		faglGetIntegerv(GET_NAME::CURRENT_PROGRAM, &program);
		glGetUniformLocation(program, name);
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

	void faglGenVertexArrays(GLsizei n, GLuint* arrays) {
		glGenVertexArrays(n, arrays);
	}

	void faglGenVertexArray(GLuint* array) {
		glGenVertexArrays(1, array);
	}

	void faglBindVertexArray(GLuint array) {
		glBindVertexArray(array);
	}

	void faglUnbindVertexArray() {
		glBindVertexArray(0);
	}

	void faglVertexAttribPointer(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, BOOLEAN normalized, GLsizei stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, (GLenum)type, (GLboolean)normalized, stride, pointer);
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
}

