#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace fagl {
	using std::string;
	using std::vector;
	using std::cout;
	using std::endl;

	GLuint CreateCubeMap(const string right, const string left, const string top, const string bottom, const string front, const string back)
	{
		GLuint textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

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
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, rWidth, rHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, rData);
		else
			cout << "Could not load right texture" << endl;
		if (lData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, lWidth, lHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, lData);
		else
			cout << "Could not load left texture" << endl;
		if (tData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, tWidth, tHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, tData);
		else
			cout << "Could not load top texture" << endl;
		if (bData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, bWidth, bHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bData);
		else
			cout << "Could not load bottom texture" << endl;
		if (fData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, fWidth, fHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, fData);
		else
			cout << "Could not load front texture" << endl;
		if (baData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, baWidth, baHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, baData);
		else
			cout << "Could not load right texture" << endl;

		stbi_image_free(rData);
		stbi_image_free(lData);
		stbi_image_free(tData);
		stbi_image_free(bData);
		stbi_image_free(fData);
		stbi_image_free(baData);

		glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);


		return textureID;
	}
	GLuint CreateCubeMap(const vector<string> paths)
	{
		return CreateCubeMap(paths[0], paths[1], paths[2], paths[3], paths[4], paths[5]);
	}
	GLuint CreateTexture(const string path)
	{
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		int width, height, nrChannels;
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			cout << "Failed to load texture" << endl;
		}
		stbi_image_free(data);
		return texture;
	}

	GLuint CreateCubeMap(const std::string right, const std::string left, const std::string top, const std::string bottom, const std::string front, const std::string back, const GLint internalformat, const GLint border, const GLenum format, const GLenum type)
	{
		GLuint textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

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
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, internalformat, rWidth, rHeight, border, format, type, rData);
		else
			cout << "Could not load right texture" << endl;
		if (lData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, internalformat, lWidth, lHeight, border, format, type, lData);
		else
			cout << "Could not load left texture" << endl;
		if (tData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, internalformat, tWidth, tHeight, border, format, type, tData);
		else
			cout << "Could not load top texture" << endl;
		if (bData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, internalformat, bWidth, bHeight, border, format, type, bData);
		else
			cout << "Could not load bottom texture" << endl;
		if (fData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, internalformat, fWidth, fHeight, border, format, type, fData);
		else
			cout << "Could not load front texture" << endl;
		if (baData)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, internalformat, baWidth, baHeight, border, format, type, baData);
		else
			cout << "Could not load right texture" << endl;

		stbi_image_free(rData);
		stbi_image_free(lData);
		stbi_image_free(tData);
		stbi_image_free(bData);
		stbi_image_free(fData);
		stbi_image_free(baData);

		glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		return textureID;
	}

	GLuint CreateCubeMap(const std::vector<std::string> paths, const GLint internalformat, const GLint border, const GLenum format, const GLenum type)
	{
		return CreateCubeMap(paths[0], paths[1], paths[2], paths[3], paths[4], paths[5], internalformat, border, format, type);
	}

	GLuint CreateTexture(const std::string path, const GLint internalformat, const GLint border, const GLenum format, const GLenum type)
	{
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		int width, height, nrChannels;
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width, height, border, format, type, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			cout << "Failed to load texture" << endl;
		}
		stbi_image_free(data);
		return texture;
	}

	void CreatePlainFrameBuffer(GLuint* framebuffer, GLuint* texture, const GLint internalformat, const GLsizei width, const GLsizei height, const GLint border, const GLenum format, const GLenum type)
	{
		glGenFramebuffers(1, framebuffer);

		glGenTextures(1, texture);
		glBindTexture(GL_TEXTURE_2D, *texture);
		glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width, height, border, format, type, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		GLuint renderbuffer;

		glGenRenderbuffers(1, &renderbuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);

		glBindFramebuffer(GL_FRAMEBUFFER, *framebuffer);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, *texture, 0);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);
		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "Framebuffer not complete!" << std::endl;
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void CreateCubeFrameBuffer(GLuint* framebuffer, GLuint* texture, const GLint internalformat, const GLsizei width, const GLsizei height, const GLint border, const GLenum format, const GLenum type)
	{
		glGenFramebuffers(1, framebuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, *framebuffer);

		glGenTextures(1, texture);
		glBindTexture(GL_TEXTURE_CUBE_MAP, *texture);

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, internalformat, width, height, border, format, type, NULL);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, internalformat, width, height, border, format, type, NULL);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, internalformat, width, height, border, format, type, NULL);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, internalformat, width, height, border, format, type, NULL);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, internalformat, width, height, border, format, type, NULL);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, internalformat, width, height, border, format, type, NULL);

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_CUBE_MAP_NEGATIVE_X, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT3, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT4, GL_TEXTURE_CUBE_MAP_POSITIVE_Z, *texture, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT5, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, *texture, 0);

		GLuint renderbuffer;

		glGenRenderbuffers(1, &renderbuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);

		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);


		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "Framebuffer not complete!" << std::endl;
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}


}