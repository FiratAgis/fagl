#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "Texture.h"

namespace fagl {
	using std::string;
	using std::vector;
	using std::cout;
	using std::endl;

	FAGLtexture CreateCubeMap(const string right, const string left, const string top, const string bottom, const string front, const string back)
	{
		FAGLtexture textureID;
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
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_X, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::RGB, rWidth, rHeight, TEXTURE_IMAGE_FORMAT::RGB, TEXTURE_IMAGE_TYPE::UNSIGNED_BYTE, rData);
		else
			cout << "Could not load right texture" << endl;
		if (lData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_X, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::RGB, lWidth, lHeight, TEXTURE_IMAGE_FORMAT::RGB, TEXTURE_IMAGE_TYPE::UNSIGNED_BYTE, lData);
		else
			cout << "Could not load left texture" << endl;
		if (tData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Y, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::RGB, tWidth, tHeight, TEXTURE_IMAGE_FORMAT::RGB, TEXTURE_IMAGE_TYPE::UNSIGNED_BYTE, tData);
		else
			cout << "Could not load top texture" << endl;
		if (bData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::RGB, bWidth, bHeight, TEXTURE_IMAGE_FORMAT::RGB, TEXTURE_IMAGE_TYPE::UNSIGNED_BYTE, bData);
		else
			cout << "Could not load bottom texture" << endl;
		if (fData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Z, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::RGB, fWidth, fHeight, TEXTURE_IMAGE_FORMAT::RGB, TEXTURE_IMAGE_TYPE::UNSIGNED_BYTE, fData);
		else
			cout << "Could not load front texture" << endl;
		if (baData)
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::RGB, baWidth, baHeight, TEXTURE_IMAGE_FORMAT::RGB, TEXTURE_IMAGE_TYPE::UNSIGNED_BYTE, baData);
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
	FAGLtexture CreateCubeMap(const vector<string> paths)
	{
		return CreateCubeMap(paths[0], paths[1], paths[2], paths[3], paths[4], paths[5]);
	}
	FAGLtexture CreateTexture(const string path)
	{
		FAGLtexture texture;
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
			faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_2D, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::RGB, width, height, TEXTURE_IMAGE_FORMAT::RGB, TEXTURE_IMAGE_TYPE::UNSIGNED_BYTE, data);
			faglGenerateMipmap(MIPMAP_TARGET::TEXTURE_2D);
		}
		else
		{
			cout << "Failed to load texture" << endl;
		}
		stbi_image_free(data);
		return texture;
	}

	FAGLtexture CreateCubeMap(const std::string right, const std::string left, const std::string top, const std::string bottom, const std::string front, const std::string back, const TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, const TEXTURE_IMAGE_FORMAT format, const TEXTURE_IMAGE_TYPE type)
	{
		FAGLtexture textureID;
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

	FAGLtexture CreateCubeMap(const std::vector<std::string> paths, const TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, const TEXTURE_IMAGE_FORMAT format, const TEXTURE_IMAGE_TYPE type)
	{
		return CreateCubeMap(paths[0], paths[1], paths[2], paths[3], paths[4], paths[5], internalformat, format, type);
	}

	FAGLtexture CreateTexture(const std::string path, const TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, const TEXTURE_IMAGE_FORMAT format, const TEXTURE_IMAGE_TYPE type)
	{
		FAGLtexture texture;
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
			faglGenerateMipmap(MIPMAP_TARGET::TEXTURE_2D);
		}
		else
		{
			cout << "Failed to load texture" << endl;
		}
		stbi_image_free(data);
		return texture;
	}

	void CreatePlainFrameBuffer(FAGLframebuffer* framebuffer, FAGLtexture* texture, const TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_FORMAT format, const TEXTURE_IMAGE_TYPE type)
	{
		faglGenFramebuffer(framebuffer);

		faglGenTexture(texture);

		faglBindTexture(BIND_TEXTURE_TARGET::TEXTURE_2D, *texture);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_2D, 0, internalformat, width, height, format, type, NULL);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MIN_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MAG_FILTER, GL_LINEAR);

		FAGLrenderbuffer renderbuffer;

		faglGenRenderbuffer(&renderbuffer);
		faglBindRenderbuffer(renderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);

		faglBindFramebuffer(*framebuffer);
		faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT::COLOR_ATTACHMENT0, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET::TEXTURE_2D, *texture);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);
		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "Framebuffer not complete!" << std::endl;
		faglUnbindFramebuffer();
	}

	void CreateCubeFrameBuffer(FAGLframebuffer* framebuffer, FAGLtexture* texture, const TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_FORMAT format, const TEXTURE_IMAGE_TYPE type)
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

		faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT::COLOR_ATTACHMENT0, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET::TEXTURE_CUBE_MAP_POSITIVE_X, *texture);
		faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT::COLOR_ATTACHMENT1, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_X, *texture);
		faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT::COLOR_ATTACHMENT2, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Y, *texture);
		faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT::COLOR_ATTACHMENT3, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Y, *texture);
		faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT::COLOR_ATTACHMENT4, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Z, *texture);
		faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT::COLOR_ATTACHMENT5, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Z, *texture);

		FAGLrenderbuffer renderbuffer;

		faglGenRenderbuffer(&renderbuffer);
		faglBindRenderbuffer(renderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
		faglUnbindRenderbuffer();

		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderbuffer);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "Framebuffer not complete!" << std::endl;
		faglUnbindFramebuffer();
	}

	void CreatePlainDepthBuffer(FAGLframebuffer* framebuffer, FAGLtexture* texture, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_TYPE type)
	{
		faglGenTexture(texture);
		faglBindTexture(BIND_TEXTURE_TARGET::TEXTURE_2D, *texture);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_2D, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::DEPTH_COMPONENT, width, height, TEXTURE_IMAGE_FORMAT::DEPTH_COMPONENT, type, NULL);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MIN_FILTER, GL_NEAREST);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_MAG_FILTER, GL_NEAREST);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_S, GL_REPEAT);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_2D, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_T, GL_REPEAT);
	
		faglGenFramebuffer(framebuffer);

		faglBindFramebuffer(*framebuffer);
		faglFramebufferTexture2D(FRAMEBUFFER_TEXTURE_ATTACHMENT::DEPTH_ATTACHMENT, FRAMEBUFFER_TEXTURE_2D_TEXTURE_TARGET::TEXTURE_2D, *texture);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
		faglUnbindFramebuffer();
	}

	void CreateCubeDepthBuffer(FAGLframebuffer* framebuffer, FAGLtexture* texture, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_TYPE type)
	{
		faglGenFramebuffer(framebuffer);
		faglBindFramebuffer(*framebuffer);

		faglGenTexture(texture);
		faglBindTexture(BIND_TEXTURE_TARGET::TEXTURE_CUBE_MAP, *texture);

		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_X, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::DEPTH_COMPONENT, width, height, TEXTURE_IMAGE_FORMAT::DEPTH_COMPONENT, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_X, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::DEPTH_COMPONENT, width, height, TEXTURE_IMAGE_FORMAT::DEPTH_COMPONENT, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Y, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::DEPTH_COMPONENT, width, height, TEXTURE_IMAGE_FORMAT::DEPTH_COMPONENT, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::DEPTH_COMPONENT, width, height, TEXTURE_IMAGE_FORMAT::DEPTH_COMPONENT, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_POSITIVE_Z, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::DEPTH_COMPONENT, width, height, TEXTURE_IMAGE_FORMAT::DEPTH_COMPONENT, type, NULL);
		faglTexImage2D(TEXTURE_IMAGE_2D_TARGET::TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, TEXTURE_IMAGE_INTERNAL_FORMAT::DEPTH_COMPONENT, width, height, TEXTURE_IMAGE_FORMAT::DEPTH_COMPONENT, type, NULL);

		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_MIN_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_MAG_FILTER, GL_LINEAR);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		faglTexParameteri(TEXTURE_PARAMETER_TARGET::TEXTURE_CUBE_MAP, TEXTURE_PARAMETER_NAME::TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		faglFramebufferTexture(FRAMEBUFFER_TEXTURE_ATTACHMENT::DEPTH_ATTACHMENT, *texture);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);


		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "Framebuffer not complete!" << std::endl;
		faglUnbindFramebuffer();
	}

	void WriteFrameBufferToFile(FAGLframebuffer framebuffer, string filename, int width, int height)
	{
		GLsizei nrChannels = 3;
		GLsizei stride = nrChannels * width;
		stride += (stride % 4) ? (4 - stride % 4) : 0;
		GLsizei bufferSize = stride * height;
		std::vector<char> buffer(bufferSize);
		glPixelStorei(GL_PACK_ALIGNMENT, 4);
		faglNamedFramebufferReadBuffer(framebuffer, READ_BUFFER_MODE::FRONT);
		faglReadPixels(width, height, READ_PIXEL_FORMAT::RGB, READ_PIXEL_TYPE::UNSIGNED_BYTE, buffer.data());
		stbi_flip_vertically_on_write(true);
		stbi_write_png(filename.c_str(), width, height, nrChannels, buffer.data(), stride);
	}
}