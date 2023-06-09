#ifndef FAGL_TEXTURE_H
#define FAGL_TEXTURE_H

#include "FAGL.h"

namespace fagl {

	/// <summary>
	/// Creates a cubemap texture with given images.
	/// </summary>
	/// <param name="right"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_POSITIVE_X.</param>
	/// <param name="left"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_NEGATIVE_X.</param>
	/// <param name="top"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_POSITIVE_Y.</param>
	/// <param name="bottom"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_NEGATIVE_Y.</param>
	/// <param name="front"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_POSITIVE_Z.</param>
	/// <param name="back"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_NEGATIVE_Z.</param>
	/// <returns> Pointer to the created texture.</returns>
	FAGLtexture CreateCubeMap(const std::string right, const std::string left, const std::string top, const std::string bottom, const std::string front, const std::string back);
	
	/// <summary>
	/// Creates a cubemap texture with given images.
	/// </summary>
	/// <param name="paths"> Paths to images that will be assigned to GL_TEXTURE_CUBE_MAP_POSITIVE_X, GL_TEXTURE_CUBE_MAP_NEGATIVE_X, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, GL_TEXTURE_CUBE_MAP_POSITIVE_Z, and GL_TEXTURE_CUBE_MAP_NEGATIVE_Z.</param>
	/// <returns> Pointer to the created texture.</returns>
	FAGLtexture CreateCubeMap(const std::vector<std::string> paths);

	/// <summary>
	/// Creates a 2d image texture with given image.
	/// </summary>
	/// <param name="path"> Path of the image that will be assigned to the texture.</param>
	/// <returns> Pointer to the created texture.</returns>
	FAGLtexture CreateTexture(const std::string path);

	/// <summary>
	/// Creates a cubemap texture with given images and parameters.
	/// </summary>
	/// <param name="right"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_POSITIVE_X.</param>
	/// <param name="left"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_NEGATIVE_X.</param>
	/// <param name="top"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_POSITIVE_Y.</param>
	/// <param name="bottom"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_NEGATIVE_Y.</param>
	/// <param name="front"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_POSITIVE_Z.</param>
	/// <param name="back"> Path of the image that will be assign to GL_TEXTURE_CUBE_MAP_NEGATIVE_Z.</param>
	/// <param name="internalformat"> Internal format of the texture.</param>
	/// <param name="format"> Format of the texture.</param>
	/// <param name="type"> Type of the texture.</param>
	/// <returns> Pointer to the created texture.</returns>
	FAGLtexture CreateCubeMap(const std::string right, const std::string left, const std::string top, const std::string bottom, const std::string front, const std::string back, const TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, const TEXTURE_IMAGE_FORMAT format, const TEXTURE_IMAGE_TYPE type);
	
	/// <summary>
	/// Creates a cubemap texture with given images and parameters.
	/// </summary>
	/// <param name="paths"> Paths to images that will be assigned to GL_TEXTURE_CUBE_MAP_POSITIVE_X, GL_TEXTURE_CUBE_MAP_NEGATIVE_X, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, GL_TEXTURE_CUBE_MAP_POSITIVE_Z, and GL_TEXTURE_CUBE_MAP_NEGATIVE_Z.</param>
	/// <param name="internalformat"> Internal format of the texture.</param>
	/// <param name="format"> Format of the texture.</param>
	/// <param name="type"> Type of the texture.</param>
	/// <returns> Pointer to the created texture.</returns>
	FAGLtexture CreateCubeMap(const std::vector<std::string> paths, const TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, const TEXTURE_IMAGE_FORMAT format, const TEXTURE_IMAGE_TYPE type);

	/// <summary>
	/// Creates a 2d image texture with given image.
	/// </summary>
	/// <param name="path"> Path of the image that will be assigned to the texture.</param>
	/// <param name="internalformat"> Internal format of the texture.</param>
	/// <param name="format"> Format of the texture.</param>
	/// <param name="type"> Type of the texture.</param>
	/// <returns> Pointer to the created texture.</returns>
	FAGLtexture CreateTexture(const std::string path, TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, TEXTURE_IMAGE_FORMAT format, TEXTURE_IMAGE_TYPE type);

	/// <summary>
	/// Creates a frame buffer and associated 2d texture to be written and read.
	/// </summary>
	/// <param name="framebuffer"> Pointer to the frame buffer.</param>
	/// <param name="texture"> Pointer to the texture.</param>
	/// <param name="internalformat"> Internal format of the texture.</param>
	/// <param name="width"> Width of the texture and the frame buffer.</param>
	/// <param name="height"> Height of the texture and the frame buffer.</param>
	/// <param name="format"> Format of the texture.</param>
	/// <param name="type"> Type of the texture.</param>
	void CreatePlainFrameBuffer(FAGLframebuffer *framebuffer, FAGLtexture*texture, const TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_FORMAT format, const TEXTURE_IMAGE_TYPE type);

	/// <summary>
	/// Creates a frame buffer and associated cubemap texture to be written and read.
	/// </summary>
	/// <param name="framebuffer"> Pointer to the frame buffer.</param>
	/// <param name="texture"> Pointer to the texture.</param>
	/// <param name="internalformat"> Internal format of the texture.</param>
	/// <param name="width"> Width of the texture and the frame buffer.</param>
	/// <param name="height"> Height of the texture and the frame buffer.</param>
	/// <param name="format"> Format of the texture.</param>
	/// <param name="type"> Type of the texture.</param>
	void CreateCubeFrameBuffer(FAGLframebuffer*framebuffer, FAGLtexture* texture, const TEXTURE_IMAGE_INTERNAL_FORMAT internalformat, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_FORMAT format, const TEXTURE_IMAGE_TYPE type);

	/// <summary>
	/// Creates a frame buffer for depth information and associated 2d texture to be written and read.
	/// </summary>
	/// <param name="framebuffer"> Pointer to the frame buffer.</param>
	/// <param name="texture"> Pointer to the texture.</param>
	/// <param name="width"> Width of the texture and the frame buffer.</param>
	/// <param name="height"> Height of the texture and the frame buffer.</param>
	/// <param name="type"> Type of the texture.</param>
	void CreatePlainDepthBuffer(FAGLframebuffer* framebuffer, FAGLtexture* texture, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_TYPE type);

	/// <summary>
	/// Creates a frame buffer for depth information and associated cubemap texture to be written and read.
	/// </summary>
	/// <param name="framebuffer"> Pointer to the frame buffer.</param>
	/// <param name="texture"> Pointer to the texture.</param>
	/// <param name="width"> Width of the texture and the frame buffer.</param>
	/// <param name="height"> Height of the texture and the frame buffer.</param>
	/// <param name="type"> Type of the texture.</param>
	void CreateCubeDepthBuffer(FAGLframebuffer* framebuffer, FAGLtexture* texture, const GLsizei width, const GLsizei height, const TEXTURE_IMAGE_TYPE type);

	/// <summary>
	/// Writes a frame buffer to a png file
	/// </summary>
	/// <param name="framebuffer"> Name of the frame buffer.</param>
	/// <param name="filename"> Name of the png file.</param>
	/// <param name="width"> Width of the frame buffer.</param>
	/// <param name="height"> Height of the frame buffer.</param>
	void WriteFrameBufferToFile(FAGLframebuffer framebuffer, string filename, int width, int height);
}

#include "Texture.inl"

#endif
