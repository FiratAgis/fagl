namespace fagl {
	inline void faglEnable(ENABLE_CAPABILITY cap)
	{
		glEnable((GLenum)cap);
	}

	inline void faglDisable(ENABLE_CAPABILITY cap)
	{
		glDisable((GLenum)cap);
	}

	inline void faglEnablei(ENABLE_CAPABILITY cap, GLuint index)
	{
		glEnablei((GLenum)cap, index);
	}

	inline void faglDisablei(ENABLE_CAPABILITY cap, GLuint index)
	{
		glDisablei((GLenum)cap, index);
	}

	inline GLboolean faglIsEnabled(ENABLE_CAPABILITY cap)
	{
		return glIsEnabled((GLenum)cap);
	}

	inline GLboolean faglIsEnabledi(ENABLE_CAPABILITY cap, GLuint index)
	{
		return glIsEnabledi((GLenum)cap, index);
	}

	inline void faglGenBuffers(GLsizei n, FAGLbuffer* buffers)
	{
		glGenBuffers(n, buffers);
	}

	inline void faglGenBuffer(FAGLbuffer* buffer)
	{
		glGenBuffers(1, buffer);
	}

	inline void faglBindBuffer(BIND_BUFFER_TARGET target, FAGLbuffer buffer)
	{
		glBindBuffer((GLenum)target, buffer);
	}

	inline void faglBufferData(BIND_BUFFER_TARGET target, GLsizeiptr size, const void* data, BUFFER_DATA_USAGE usage)
	{
		glBufferData((GLenum)target, size, data, (GLenum)usage);
	}

	inline void faglNamedBufferData(FAGLbuffer buffer, GLsizeiptr size, const void* data, BUFFER_DATA_USAGE usage)
	{
		glNamedBufferData(buffer, size, data, (GLenum)usage);
	}

	inline void faglGenTextures(GLsizei n, FAGLtexture* textures)
	{
		glGenTextures(n, textures);
	}

	inline void faglGenTexture(FAGLtexture* texture)
	{
		glGenTextures(1, texture);
	}

	inline void faglGenFramebuffers(GLsizei n, FAGLframebuffer* ids)
	{
		glGenFramebuffers(n, ids);
	}

	inline void faglGenFramebuffer(FAGLframebuffer* id)
	{
		glGenFramebuffers(1, id);
	}

	inline void faglBindFramebuffer(BIND_FRAMEBUFFER_TARGET target, FAGLframebuffer framebuffer)
	{
		glBindFramebuffer((GLenum)target, framebuffer);
	}

	inline void faglBindFramebuffer(FAGLframebuffer framebuffer)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	}

	inline void faglUnbindFramebuffer()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	inline void faglGenRenderbuffers(GLsizei n, FAGLrenderbuffer* renderbuffers)
	{
		glGenRenderbuffers(n, renderbuffers);
	}

	inline void faglGenRenderbuffer(FAGLrenderbuffer* renderbuffer)
	{
		glGenRenderbuffers(1, renderbuffer);
	}

	inline void faglBindRenderbuffer(FAGLrenderbuffer renderbuffer)
	{
		glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
	}

	inline void faglUnbindRenderbuffer()
	{
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}

	inline void faglTexImage3D(TEXTURE_IMAGE_3D_TARGET target, GLint level, TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, GLsizei width, GLsizei height, GLsizei depth, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* data)
	{
		glTexImage3D((GLenum)target, level, (GLint)internalformat, width, height, depth, 0, (GLenum)format, (GLenum)type, data);
	}

	inline void faglTexImage2D(TEXTURE_IMAGE_2D_TARGET target, GLint level, TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, GLsizei width, GLsizei height, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* data)
	{
		glTexImage2D((GLenum)target, level, (GLint)internalformat, width, height, 0, (GLenum)format, (GLenum)type, data);
	}

	inline void faglTexImage1D(TEXTURE_IMAGE_1D_TARGET target, GLint level, TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, GLsizei width, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* data)
	{
		glTexImage1D((GLenum)target, level, (GLint)internalformat, width, 0, (GLenum)format, (GLenum)type, data);
	}

	inline void faglTexSubImage3D(TEXTURE_SUB_3D_TARGET target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTexSubImage3D((GLenum)target, level, xoffset, yoffset, zoffset, width, height, depth, (GLenum)format, (GLenum)type, pixels);
	}

	inline void faglTextureSubImage3D(FAGLtexture texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, (GLenum)format, (GLenum)type, pixels);
	}

	inline void faglTexSubImage2D(TEXTURE_SUB_2D_TARGET target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTexSubImage2D((GLenum)target, level, xoffset, yoffset, width, height, (GLenum)format, (GLenum)type, pixels);
	}

	inline void faglTextureSubImage2D(FAGLtexture texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, (GLenum)format, (GLenum)type, pixels);
	}

	inline void faglTexSubImage1D(GLint level, GLint xoffset, GLsizei width, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, (GLenum)format, (GLenum)type, pixels);
	}

	inline void faglTextureSubImage1D(FAGLtexture texture, GLint level, GLint xoffset, GLsizei width, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type, const void* pixels)
	{
		glTextureSubImage1D(texture, level, xoffset, width, (GLenum)format, (GLenum)type, pixels);
	}

	inline void faglBindTexture(BIND_TEXTURE_TARGET target, FAGLtexture texture)
	{
		glBindTexture((GLenum)target, texture);
	}

	inline void faglTexParameterf(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, GLfloat param)
	{
		glTexParameterf((GLenum)target, (GLenum)pname, param);
	}

	inline void faglTexParameteri(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, GLint param)
	{
		glTexParameteri((GLenum)target, (GLenum)pname, param);
	}

	inline void faglTextureParameterf(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, GLfloat param)
	{
		glTextureParameterf(texture, (GLenum)pname, param);
	}

	inline void faglTextureParameteri(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, GLint param)
	{
		glTextureParameteri(texture, (GLenum)pname, param);
	}

	inline void faglTexParameterfv(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, const GLfloat* params)
	{
		glTexParameterfv((GLenum)target, (GLenum)pname, params);
	}

	inline void faglTexParameteriv(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTexParameteriv((GLenum)target, (GLenum)pname, params);
	}

	inline void faglTexParameterIiv(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTexParameterIiv((GLenum)target, (GLenum)pname, params);
	}

	inline void faglTexParameterIuiv(TEXTURE_PARAMETER_TARGET target, TEXTURE_PARAMETER_NAME pname, const GLuint* params)
	{
		glTexParameterIuiv((GLenum)target, (GLenum)pname, params);
	}

	inline void faglTextureParameterfv(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, const GLfloat* params)
	{
		glTextureParameterfv(texture, (GLenum)pname, params);
	}

	inline void faglTextureParameteriv(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTextureParameteriv(texture, (GLenum)pname, params);
	}

	inline void faglTextureParameterIiv(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, const GLint* params)
	{
		glTextureParameterIiv(texture, (GLenum)pname, params);
	}

	inline void faglTextureParameterIuiv(FAGLtexture texture, TEXTURE_PARAMETER_NAME pname, const GLuint* params)
	{
		glTextureParameterIuiv(texture, (GLenum)pname, params);
	}

	inline void faglPixelStoref(PIXEL_STORE_NAME pname, GLfloat param)
	{
		glPixelStoref((GLenum)pname, param);
	}

	inline void faglPixelStorei(PIXEL_STORE_NAME pname, GLint param)
	{
		glPixelStorei((GLenum)pname, param);
	}

	inline void faglGenerateMipmap(MIPMAP_TARGET target)
	{
		glGenerateMipmap((GLenum)target);
	}

	inline void faglGenerateTextureMipmap(FAGLtexture texture)
	{
		glGenerateTextureMipmap(texture);
	}
	inline FAGLprogram faglCreateProgram()
	{
		return glCreateProgram();
	}
	inline void faglUseProgram(FAGLprogram program)
	{
		glUseProgram(program);
	}
	inline void faglLinkProgram(FAGLprogram program)
	{
		glLinkProgram(program);
	}
	inline FAGLshader faglCreateShader(CREATE_SHADER_TYPE shaderType)
	{
		return glCreateShader((GLenum)shaderType);
	}
	inline void faglShaderSource(FAGLshader shader, GLsizei count, const GLchar** string, const GLint* length)
	{
		glShaderSource(shader, count, string, length);
	}
	inline void faglCompileShader(FAGLshader shader)
	{
		glCompileShader(shader);
	}
	inline void faglGetShaderInfoLog(FAGLshader shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog)
	{
		glGetShaderInfoLog(shader, maxLength, length, infoLog);
	}
	inline void faglReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, READ_PIXEL_FORMAT format, READ_PIXEL_TYPE type, void* data)
	{
		glReadPixels(x, y, width, height, (GLenum)format, (GLenum)type, data);
	}
	inline void faglReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, READ_PIXEL_FORMAT format, READ_PIXEL_TYPE type, GLsizei bufSize, void* data)
	{
		glReadnPixels(x, y, width, height, (GLenum)format, (GLenum)type, bufSize, data);
	}
	inline void faglReadPixels(GLsizei width, GLsizei height, READ_PIXEL_FORMAT format, READ_PIXEL_TYPE type, void* data)
	{
		glReadPixels(0, 0, width, height, (GLenum)format, (GLenum)type, data);
	}
	inline void faglReadnPixels(GLsizei width, GLsizei height, READ_PIXEL_FORMAT format, READ_PIXEL_TYPE type, GLsizei bufSize, void* data)
	{
		glReadnPixels(0, 0, width, height, (GLenum)format, (GLenum)type, bufSize, data);
	}

	inline FAGLuniform faglGetUniformLocation(FAGLprogram program, const GLchar* name)
	{
		return glGetUniformLocation(program, name);
	}

	inline FAGLuniform faglGetUniformLocation(const GLchar* name)
	{
		GLint program;
		faglGetIntegerv(GET_NAME::CURRENT_PROGRAM, &program);
		return glGetUniformLocation(program, name);
	}

	inline void faglGetBooleanv(GET_NAME pname, GLboolean* data)
	{
		glGetBooleanv((GLenum)pname, data);
	}

	inline void faglGetDoublev(GET_NAME pname, GLdouble* data)
	{
		glGetDoublev((GLenum)pname, data);
	}

	inline void faglGetFloatv(GET_NAME pname, GLfloat* data)
	{
		glGetFloatv((GLenum)pname, data);
	}

	inline void faglGetIntegerv(GET_NAME pname, GLint* data)
	{
		glGetIntegerv((GLenum)pname, data);
	}

	inline void faglGetInteger64v(GET_NAME pname, GLint64* data)
	{
		glGetInteger64v((GLenum)pname, data);
	}

	inline void faglGetBooleani_v(GET_NAME target, GLuint index, GLboolean* data)
	{
		glGetBooleani_v((GLenum)target, index, data);
	}

	inline void faglGetIntegeri_v(GET_NAME target, GLuint index, GLint* data)
	{
		glGetIntegeri_v((GLenum)target, index, data);
	}

	inline void faglGetFloati_v(GET_NAME target, GLuint index, GLfloat* data)
	{
		glGetFloati_v((GLenum)target, index, data);
	}

	inline void faglGetDoublei_v(GET_NAME target, GLuint index, GLdouble* data)
	{
		glGetDoublei_v((GLenum)target, index, data);
	}

	inline void faglGetInteger64i_v(GET_NAME target, GLuint index, GLint64* data)
	{
		glGetInteger64i_v((GLenum)target, index, data);
	}

	inline void faglGenVertexArrays(GLsizei n, FAGLvertexarrar* arrays) {
		glGenVertexArrays(n, arrays);
	}

	inline void faglGenVertexArray(FAGLvertexarrar* array) {
		glGenVertexArrays(1, array);
	}

	inline void faglBindVertexArray(FAGLvertexarrar array) {
		glBindVertexArray(array);
	}

	inline void faglUnbindVertexArray() {
		glBindVertexArray(0);
	}

	inline void faglVertexAttribPointer(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, BOOLEAN normalized, GLsizei stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, (GLenum)type, (GLboolean)normalized, stride, pointer);
	}

	inline void faglVertexAttribPointer(GLuint index, GLint size, BOOLEAN normalized, GLsizei stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, GL_FLOAT, (GLboolean)normalized, stride, pointer);
	}

	inline void faglVertexAttribPointer(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, (GLenum)type, GL_FALSE, stride, pointer);
	}

	inline void faglVertexAttribPointer(GLuint index, GLint size, GLsizei stride, const void* pointer)
	{
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
	}

	inline void faglVertexAttribIPointer(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glVertexAttribIPointer(index, size, (GLenum)type, stride, pointer);
	}

	inline void faglVertexAttribIPointer(GLuint index, GLint size, GLsizei stride, const void* pointer)
	{
		glVertexAttribIPointer(index, size, GL_FLOAT, stride, pointer);
	}

	inline void faglVertexAttribLPointer(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glVertexAttribLPointer(index, size, (GLenum)type, stride, pointer);
	}

	inline void faglVertexAttribLPointer(GLuint index, GLint size, GLsizei stride, const void* pointer)
	{
		glVertexAttribLPointer(index, size, GL_FLOAT, stride, pointer);
	}

	inline void faglVertexAttribPointerC(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, BOOLEAN normalized, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, (GLenum)type, (GLboolean)normalized, stride, pointer);
	}

	inline void faglVertexAttribPointerC(GLuint index, GLint size, BOOLEAN normalized, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, GL_FLOAT, (GLboolean)normalized, stride, pointer);
	}

	inline void faglVertexAttribPointerC(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, (GLenum)type, GL_FALSE, stride, pointer);
	}

	inline void faglVertexAttribPointerC(GLuint index, GLint size, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
	}

	inline void faglVertexAttribIPointerC(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribIPointer(index, size, (GLenum)type, stride, pointer);
	}

	inline void faglVertexAttribIPointerC(GLuint index, GLint size, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribIPointer(index, size, GL_FLOAT, stride, pointer);
	}

	inline void faglVertexAttribLPointerC(GLuint index, GLint size, VERTEX_ATTRIB_POINTER_TYPE type, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribLPointer(index, size, (GLenum)type, stride, pointer);
	}

	inline void faglVertexAttribLPointerC(GLuint index, GLint size, GLsizei stride, const void* pointer)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribLPointer(index, size, GL_FLOAT, stride, pointer);
	}

	inline void faglDrawArrays(DRAW_MODE mode, GLint first, GLsizei count)
	{
		glDrawArrays((GLenum)mode, first, count);
	}

	inline void faglDrawArrays(DRAW_MODE mode, GLsizei count)
	{
		glDrawArrays((GLenum)mode, 0, count);
	}

	inline void faglDrawElements(DRAW_MODE mode, GLsizei count, DRAW_TYPE type, const void* indices)
	{
		glDrawElements((GLenum)mode, count, (GLenum)type, indices);
	}
	inline void faglAttachShader(FAGLprogram program, FAGLshader shader)
	{
		glAttachShader(program, shader);
	}
	inline void faglAttachShader(FAGLprogram program, GLuint count, FAGLshader* shaders)
	{
		for(GLuint i = 0; i < count; i++)
			glAttachShader(program, shaders[i]);
	}
	inline void faglAttachShader(FAGLprogram program, std::vector<FAGLshader> shaders)
	{
		for(GLuint shader : shaders)
			glAttachShader(program, shader);
	}
	inline void faglReadBuffer(READ_BUFFER_MODE mode)
	{
		glReadBuffer((GLenum)mode);
	}
	inline void faglNamedFramebufferReadBuffer(FAGLframebuffer framebuffer, READ_BUFFER_MODE mode)
	{
		glNamedFramebufferReadBuffer(framebuffer, (GLenum)mode);
	}
	inline void faglUniform1f(FAGLuniform location, GLfloat v0)
	{
		glUniform1f(location, v0);
	}
	inline void faglUniform2f(FAGLuniform location, GLfloat v0, GLfloat v1)
	{
		glUniform2f(location, v0, v1);
	}
	inline void faglUniform3f(FAGLuniform location, GLfloat v0, GLfloat v1, GLfloat v2)
	{
		glUniform3f(location, v0, v1, v2);
	}
	inline void faglUniform4f(FAGLuniform location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	{
		glUniform4f(location, v0, v1, v2, v3);
	}
	inline void faglUniform1i(FAGLuniform location, GLint v0)
	{
		glUniform1i(location, v0);
	}
	inline void faglUniform2i(FAGLuniform location, GLint v0, GLint v1)
	{
		glUniform2i(location, v0, v1);
	}
	inline void faglUniform3i(FAGLuniform location, GLint v0, GLint v1, GLint v2)
	{
		glUniform3i(location, v0, v1, v2);
	}
	inline void faglUniform4i(FAGLuniform location, GLint v0, GLint v1, GLint v2, GLint v3)
	{
		glUniform4i(location, v0, v1, v2, v3);
	}
	inline void faglUniform1ui(FAGLuniform location, GLuint v0)
	{
		glUniform1ui(location, v0);
	}
	inline void faglUniform2ui(FAGLuniform location, GLuint v0, GLuint v1)
	{
		glUniform2ui(location, v0, v1);
	}
	inline void faglUniform3ui(FAGLuniform location, GLuint v0, GLuint v1, GLuint v2)
	{
		glUniform3ui(location, v0, v1, v2);
	}
	inline void faglUniform4ui(FAGLuniform location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
	{
		glUniform4ui(location, v0, v1, v2, v3);
	}
	inline void faglUniform1fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniform1fv(location, count, value);
	}
	inline void faglUniform1fv(FAGLuniform location, const GLfloat* value)
	{
		glUniform1fv(location, 1, value);
	}
	inline void faglUniform2fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniform2fv(location, count, value);
	}
	inline void faglUniform2fv(FAGLuniform location, const GLfloat* value)
	{
		glUniform2fv(location, 1, value);
	}
	inline void faglUniform3fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniform3fv(location, count, value);
	}
	inline void faglUniform3fv(FAGLuniform location, const GLfloat* value)
	{
		glUniform3fv(location, 1, value);
	}
	inline void faglUniform4fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniform4fv(location, count, value);
	}
	inline void faglUniform4fv(FAGLuniform location, const GLfloat* value)
	{
		glUniform4fv(location, 1, value);
	}
	inline void faglUniform1iv(FAGLuniform location, GLsizei count, const GLint* value)
	{
		glUniform1iv(location, count, value);
	}
	inline void faglUniform1iv(FAGLuniform location, const GLint* value)
	{
		glUniform1iv(location, 1, value);
	}
	inline void faglUniform2iv(FAGLuniform location, GLsizei count, const GLint* value)
	{
		glUniform2iv(location, count, value);
	}
	inline void faglUniform2iv(FAGLuniform location, const GLint* value)
	{
		glUniform2iv(location, 1, value);
	}
	inline void faglUniform3iv(FAGLuniform location, GLsizei count, const GLint* value)
	{
		glUniform3iv(location, count, value);
	}
	inline void faglUniform3iv(FAGLuniform location, const GLint* value)
	{
		glUniform3iv(location, 1, value);
	}
	inline void faglUniform4iv(FAGLuniform location, GLsizei count, const GLint* value)
	{
		glUniform4iv(location, count, value);
	}
	inline void faglUniform4iv(FAGLuniform location, const GLint* value)
	{
		glUniform4iv(location, 1, value);
	}
	inline void faglUniform1uiv(FAGLuniform location, GLsizei count, const GLuint* value)
	{
		glUniform1uiv(location, count, value);
	}
	inline void faglUniform1uiv(FAGLuniform location, const GLuint* value)
	{
		glUniform1uiv(location, 1, value);
	}
	inline void faglUniform2uiv(FAGLuniform location, GLsizei count, const GLuint* value)
	{
		glUniform2uiv(location, count, value);
	}
	inline void faglUniform2uiv(FAGLuniform location, const GLuint* value)
	{
		glUniform2uiv(location, 1, value);
	}
	inline void faglUniform3uiv(FAGLuniform location, GLsizei count, const GLuint* value)
	{
		glUniform3uiv(location, count, value);
	}
	inline void faglUniform3uiv(FAGLuniform location, const GLuint* value)
	{
		glUniform3uiv(location, 1, value);
	}
	inline void faglUniform4uiv(FAGLuniform location, GLsizei count, const GLuint* value)
	{
		glUniform4uiv(location, count, value);
	}
	inline void faglUniform4uiv(FAGLuniform location, const GLuint* value)
	{
		glUniform4uiv(location, 1, value);
	}
	inline void faglUniformMatrix2fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2fv(location, count, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix2fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2fv(location, 1, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix2fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix2fv(location, count, GL_FALSE, value);
	}
	inline void faglUniformMatrix2fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix2fv(location, 1, GL_FALSE, value);
	}
	inline void faglUniformMatrix3fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3fv(location, count, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix3fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3fv(location, 1, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix3fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix3fv(location, count, GL_FALSE, value);
	}
	inline void faglUniformMatrix3fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix3fv(location, 1, GL_FALSE, value);
	}
	inline void faglUniformMatrix4fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4fv(location, count, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix4fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4fv(location, 1, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix4fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix4fv(location, count, GL_FALSE, value);
	}
	inline void faglUniformMatrix4fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, value);
	}
	inline void faglUniformMatrix2x3fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2x3fv(location, count, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix2x3fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2x3fv(location, 1, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix2x3fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix2x3fv(location, count, GL_FALSE, value);
	}
	inline void faglUniformMatrix2x3fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix2x3fv(location, 1, GL_FALSE, value);
	}
	inline void faglUniformMatrix3x2fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3x2fv(location, count, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix3x2fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3x2fv(location, 1, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix3x2fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix3x2fv(location, count, GL_FALSE, value);
	}
	inline void faglUniformMatrix3x2fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix3x2fv(location, 1, GL_FALSE, value);
	}
	inline void faglUniformMatrix2x4fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2x4fv(location, count, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix2x4fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix2x4fv(location, 1, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix2x4fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix2x4fv(location, count, GL_FALSE, value);
	}
	inline void faglUniformMatrix2x4fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix2x4fv(location, 1, GL_FALSE, value);
	}
	inline void faglUniformMatrix4x2fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4x2fv(location, count, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix4x2fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4x2fv(location, 1, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix4x2fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix4x2fv(location, count, GL_FALSE, value);
	}
	inline void faglUniformMatrix4x2fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix4x2fv(location, 1, GL_FALSE, value);
	}
	inline void faglUniformMatrix3x4fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3x4fv(location, count, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix3x4fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix3x4fv(location, 1, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix3x4fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix3x4fv(location, count, GL_FALSE, value);
	}
	inline void faglUniformMatrix3x4fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix3x4fv(location, 1, GL_FALSE, value);
	}
	inline void faglUniformMatrix4x3fv(FAGLuniform location, GLsizei count, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4x3fv(location, count, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix4x3fv(FAGLuniform location, BOOLEAN transpose, const GLfloat* value)
	{
		glUniformMatrix4x3fv(location, 1, (GLboolean)transpose, value);
	}
	inline void faglUniformMatrix4x3fv(FAGLuniform location, GLsizei count, const GLfloat* value)
	{
		glUniformMatrix4x3fv(location, count, GL_FALSE, value);
	}
	inline void faglUniformMatrix4x3fv(FAGLuniform location, const GLfloat* value)
	{
		glUniformMatrix4x3fv(location, 1, GL_FALSE, value);
	}
	inline void faglDepthFunc(DEPTH_FUNC func)
	{
		glDepthFunc((GLenum)func);
	}
	inline void faglBlendFunc(BLEND_FUNC sfactor, BLEND_FUNC dfactor)
	{
		glBlendFunc((GLenum)sfactor, (GLenum)dfactor);
	}
	inline void faglBlendFunci(GLuint buf, BLEND_FUNC sfactor, BLEND_FUNC dfactor)
	{
		glBlendFunci(buf, (GLenum)sfactor, (GLenum)dfactor);
	}
	inline void faglFramebufferTexture(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture((GLenum)target, (GLenum)attachment, texture, level);
	}
	inline void faglFramebufferTexture(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glFramebufferTexture((GLenum)target, (GLenum)attachment, texture, 0);
	}
	inline void faglFramebufferTexture(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture(GL_FRAMEBUFFER, (GLenum)attachment, texture, level);
	}
	inline void faglFramebufferTexture(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glFramebufferTexture(GL_FRAMEBUFFER, (GLenum)attachment, texture, 0);
	}
	inline void faglFramebufferTexture1D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture1D((GLenum)target, (GLenum)attachment, GL_TEXTURE_1D, texture, level);
	}
	inline void faglFramebufferTexture1D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glFramebufferTexture1D((GLenum)target, (GLenum)attachment, GL_TEXTURE_1D, texture, 0);
	}
	inline void faglFramebufferTexture1D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture1D(GL_FRAMEBUFFER, (GLenum)attachment, GL_TEXTURE_1D, texture, level);
	}
	inline void faglFramebufferTexture1D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glFramebufferTexture1D(GL_FRAMEBUFFER, (GLenum)attachment, GL_TEXTURE_1D, texture, 0);
	}
	inline void faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET textarget, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture2D((GLenum)target, (GLenum)attachment, (GLenum)textarget, texture, level);
	}
	inline void faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET textarget, FAGLtexture texture)
	{
		glFramebufferTexture2D((GLenum)target, (GLenum)attachment, (GLenum)textarget, texture, 0);
	}
	inline void faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET textarget, FAGLtexture texture, GLint level)
	{
		glFramebufferTexture2D(GL_FRAMEBUFFER, (GLenum)attachment, (GLenum)textarget, texture, level);
	}
	inline void faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET textarget, FAGLtexture texture)
	{
		glFramebufferTexture2D(GL_FRAMEBUFFER, (GLenum)attachment, (GLenum)textarget, texture, 0);
	}
	inline void faglFramebufferTexture3D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level, GLint layer)
	{
		glFramebufferTexture3D((GLenum)target, (GLenum)attachment, GL_TEXTURE_3D, texture, level, layer);
	}
	inline void faglFramebufferTexture3D(FRAMEBUFFER_TEXTURE_TARGET target, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint layer)
	{
		glFramebufferTexture3D((GLenum)target, (GLenum)attachment, GL_TEXTURE_3D, texture, 0, layer);
	}
	inline void faglFramebufferTexture3D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level, GLint layer)
	{
		glFramebufferTexture3D(GL_FRAMEBUFFER, (GLenum)attachment, GL_TEXTURE_3D, texture, level, layer);
	}
	inline void faglFramebufferTexture3D(FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint layer)
	{
		glFramebufferTexture3D(GL_FRAMEBUFFER, (GLenum)attachment, GL_TEXTURE_3D, texture, 0, layer);
	}
	inline void faglNamedFramebufferTexture(FAGLframebuffer framebuffer, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture, GLint level)
	{
		glNamedFramebufferTexture(framebuffer, (GLenum)attachment, texture, level);
	}
	inline void faglNamedFramebufferTexture(FAGLframebuffer framebuffer, FRAMEBUFFER_TEXTURE_ATTACHMENT attachment, FAGLtexture texture)
	{
		glNamedFramebufferTexture(framebuffer, (GLenum)attachment, texture, 0);
	}
}
