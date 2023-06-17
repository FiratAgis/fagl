#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Texture.h"

namespace fagl {
	using std::string;
	using std::vector;
	using std::cout;
	using std::endl;

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

	GLuint CreateCubeMap(const string right, const string left, const string top, const string bottom, const string front, const string back)
	{
		GLuint textureID;
		faglGenTexture(&textureID);
		faglBindTexture(BIND_TEXTURE_TARGET::TEXTURE_CUBE_MAP, textureID);

		int rWidth, lWidth, tWidth, bWidth, fWidth, baWidth;
		int rHeight, lHeight, tHeight, bHeight, fHeight, baHeight;
		int rChannels, lChannels, tChannels, bChannels, fChannels, baChannels;

		unsigned char* rData = stbi_load(right.c_str(), &rWidth, &rHeight, &rChannels, 0);
		unsigned char* lData = stbi_load(left.c_str(), &lWidth, &lHeight, &lChannels, 0);
		unsigned char* tData = stbi_load(top.c_str(), &tWidth, &tHeight, &tChannels, 0);
		unsigned char* bData = stbi_load(bottom.c_str(), &bWidth, &bHeight, &bChannels, 0);
		unsigned char* fData = stbi_load(front.c_str(), &fWidth, &fHeight, &fChannels, 0);
		unsigned char* baData = stbi_load(back.c_str(), &baWidth, &baHeight, &baChannels, 0);

		if (rData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_X, 0, TEXTURE_IMAGE_2D_INTERNAL_FORMAT::RGB, rWidth, rHeight, TEXTURE_IMAGE_2D_FORMAT::RGB, TEXTURE_IMAGE_2D_TYPE::UNSIGNED_BYTE, rData);
		else
			cout << "Could not load right texture" << endl;
		if (lData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_X, 0, TEXTURE_IMAGE_2D_INTERNAL_FORMAT::RGB, lWidth, lHeight, TEXTURE_IMAGE_2D_FORMAT::RGB, TEXTURE_IMAGE_2D_TYPE::UNSIGNED_BYTE, lData);
		else
			cout << "Could not load left texture" << endl;
		if (tData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Y, 0, TEXTURE_IMAGE_2D_INTERNAL_FORMAT::RGB, tWidth, tHeight, TEXTURE_IMAGE_2D_FORMAT::RGB, TEXTURE_IMAGE_2D_TYPE::UNSIGNED_BYTE, tData);
		else
			cout << "Could not load top texture" << endl;
		if (bData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, TEXTURE_IMAGE_2D_INTERNAL_FORMAT::RGB, bWidth, bHeight, TEXTURE_IMAGE_2D_FORMAT::RGB, TEXTURE_IMAGE_2D_TYPE::UNSIGNED_BYTE, bData);
		else
			cout << "Could not load bottom texture" << endl;
		if (fData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Z, 0, TEXTURE_IMAGE_2D_INTERNAL_FORMAT::RGB, fWidth, fHeight, TEXTURE_IMAGE_2D_FORMAT::RGB, TEXTURE_IMAGE_2D_TYPE::UNSIGNED_BYTE, fData);
		else
			cout << "Could not load front texture" << endl;
		if (baData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, TEXTURE_IMAGE_2D_INTERNAL_FORMAT::RGB, baWidth, baHeight, TEXTURE_IMAGE_2D_FORMAT::RGB, TEXTURE_IMAGE_2D_TYPE::UNSIGNED_BYTE, baData);
		else
			cout << "Could not load right texture" << endl;

		stbi_image_free(rData);
		stbi_image_free(lData);
		stbi_image_free(tData);
		stbi_image_free(bData);
		stbi_image_free(fData);
		stbi_image_free(baData);

		faglEnable(ENABLE_CAPABILITY::TEXTURE_CUBE_MAP_SEAMLESS);

		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_MIN_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_MAG_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);


		return textureID;
	}
	GLuint CreateCubeMap(const vector<string> paths)
	{
		return CreateCubeMap(paths[0], paths[1], paths[2], paths[3], paths[4], paths[5]);
	}
	GLuint CreateTexture(const string path)
	{
		GLuint texture;
		faglGenTexture(&texture);
		faglBindTexture(BIND_TEXTURE_TARGET::TEXTURE_2D, texture);

		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_S, GL_REPEAT);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_T, GL_REPEAT);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MAG_FILTER, GL_LINEAR);

		faglPixelStorei(PIXEL_STORE_NAME::UNPACK_ALIGNMENT, 1);

		int width, height, nrChannels;
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_2D, 0, TEXTURE_IMAGE_2D_INTERNAL_FORMAT::RGB, width, height, TEXTURE_IMAGE_2D_FORMAT::RGB, TEXTURE_IMAGE_2D_TYPE::UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			cout << "Failed to load texture" << endl;
		}
		stbi_image_free(data);
		return texture;
	}

	GLuint CreateCubeMap(const std::string right, const std::string left, const std::string top, const std::string bottom, const std::string front, const std::string back, const TEXTURE_IMAGE_2D_INTERNAL_FORMAT internalformat, const TEXTURE_IMAGE_2D_FORMAT format, const TEXTURE_IMAGE_2D_TYPE type)
	{
		GLuint textureID;
		faglGenTexture(&textureID);
		faglBindTexture(BIND_TEXTURE_TARGET::TEXTURE_CUBE_MAP, textureID);

		int rWidth, lWidth, tWidth, bWidth, fWidth, baWidth;
		int rHeight, lHeight, tHeight, bHeight, fHeight, baHeight;
		int rChannels, lChannels, tChannels, bChannels, fChannels, baChannels;

		unsigned char* rData = stbi_load(right.c_str(), &rWidth, &rHeight, &rChannels, 0);
		unsigned char* lData = stbi_load(left.c_str(), &lWidth, &lHeight, &lChannels, 0);
		unsigned char* tData = stbi_load(top.c_str(), &tWidth, &tHeight, &tChannels, 0);
		unsigned char* bData = stbi_load(bottom.c_str(), &bWidth, &bHeight, &bChannels, 0);
		unsigned char* fData = stbi_load(front.c_str(), &fWidth, &fHeight, &fChannels, 0);
		unsigned char* baData = stbi_load(back.c_str(), &baWidth, &baHeight, &baChannels, 0);

		if (rData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_X, 0, internalformat, rWidth, rHeight, format, type, rData);
		else
			cout << "Could not load right texture" << endl;
		if (lData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_X, 0, internalformat, lWidth, lHeight, format, type, lData);
		else
			cout << "Could not load left texture" << endl;
		if (tData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Y, 0, internalformat, tWidth, tHeight, format, type, tData);
		else
			cout << "Could not load top texture" << endl;
		if (bData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, internalformat, bWidth, bHeight, format, type, bData);
		else
			cout << "Could not load bottom texture" << endl;
		if (fData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Z, 0, internalformat, fWidth, fHeight, format, type, fData);
		else
			cout << "Could not load front texture" << endl;
		if (baData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, internalformat, baWidth, baHeight, format, type, baData);
		else
			cout << "Could not load right texture" << endl;

		stbi_image_free(rData);
		stbi_image_free(lData);
		stbi_image_free(tData);
		stbi_image_free(bData);
		stbi_image_free(fData);
		stbi_image_free(baData);

		faglEnable(ENABLE_CAPABILITY::TEXTURE_CUBE_MAP_SEAMLESS);

		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_MIN_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_MAG_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		return textureID;
	}

	GLuint CreateCubeMap(const std::vector<std::string> paths, const TEXTURE_IMAGE_2D_INTERNAL_FORMAT internalformat, const TEXTURE_IMAGE_2D_FORMAT format, const TEXTURE_IMAGE_2D_TYPE type)
	{
		return CreateCubeMap(paths[0], paths[1], paths[2], paths[3], paths[4], paths[5], internalformat, format, type);
	}

	GLuint CreateTexture(const std::string path, const TEXTURE_IMAGE_2D_INTERNAL_FORMAT internalformat, const TEXTURE_IMAGE_2D_FORMAT format, const TEXTURE_IMAGE_2D_TYPE type)
	{
		GLuint texture;
		faglGenTexture(&texture);
		faglBindTexture(BIND_TEXTURE_TARGET::TEXTURE_2D, texture);

		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_S, GL_REPEAT);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_T, GL_REPEAT);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MAG_FILTER, GL_LINEAR);

		faglPixelStorei(PIXEL_STORE_NAME::UNPACK_ALIGNMENT, 1);

		int width, height, nrChannels;
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_2D, 0, internalformat, width, height, format, type, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			cout << "Failed to load texture" << endl;
		}
		stbi_image_free(data);
		return texture;
	}

	void CreatePlainFrameBuffer(GLuint* framebuffer, GLuint* texture, const TEXTURE_IMAGE_2D_INTERNAL_FORMAT internalformat, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_2D_FORMAT format, const TEXTURE_IMAGE_2D_TYPE type)
	{
		faglGenFramebuffer(framebuffer);

		faglGenTexture(texture);

		faglBindTexture(BIND_TEXTURE_TARGET::TEXTURE_2D, *texture);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_2D, 0, internalformat, width, height, format, type, NULL);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MIN_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MAG_FILTER, GL_LINEAR);

		GLuint renderbuffer;

		faglGenRenderbuffer(&renderbuffer);
		faglBindRenderbuffer(renderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);

		faglBindFramebuffer(*framebuffer);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, *texture, 0);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);
		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "Framebuffer not complete!" << std::endl;
		faglUnbindFramebuffer();
	}

	void CreateCubeFrameBuffer(GLuint* framebuffer, GLuint* texture, const TEXTURE_IMAGE_2D_INTERNAL_FORMAT internalformat, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_2D_FORMAT format, const TEXTURE_IMAGE_2D_TYPE type)
	{
		faglGenFramebuffer(framebuffer);
		faglBindFramebuffer(*framebuffer);

		faglGenTexture(texture);
		faglBindTexture(BIND_TEXTURE_TARGET::TEXTURE_CUBE_MAP, *texture);

		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_X, 0, internalformat, width, height, format, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_X, 0, internalformat, width, height, format, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Y, 0, internalformat, width, height, format, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, internalformat, width, height, format, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Z, 0, internalformat, width, height, format, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, internalformat, width, height, format, type, NULL);

		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_MIN_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_MAG_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_CUBE_MAP_NEGATIVE_X, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT3, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT4, GL_TEXTURE_CUBE_MAP_POSITIVE_Z, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT5, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, *texture, 0);

		GLuint renderbuffer;

		faglGenRenderbuffer(&renderbuffer);
		faglBindRenderbuffer(renderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
		faglUnbindRenderbuffer();

		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "Framebuffer not complete!" << std::endl;
		faglUnbindFramebuffer();
	}


}