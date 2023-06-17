#ifndef FAGL_BASIC_TYPES_H
#define FAGL_BASIC_TYPES_H

#include "CommonInclude.h"

namespace fagl {
	enum class COLOR {
		WHITE, SILVER, GRAY, BLACK, RED, MAROON, YELLOW, OLIVE, LIME, GREEN, AQUA, TEAL, BLUE, NAVY, FUCHSIA, PURPLE
	};
	
	enum class ATTRIBUTE_TYPE {
		POSITION, NORMAL, TEXTURE, AMBIENT_COLOR, DIFFUSE_COLOR, SPECULAR_COLOR, TRANSPERANCY, DENSITY, ILLUMINATION_MODEL, 
		CUSTOM_VEC1_0, CUSTOM_VEC1_1, CUSTOM_VEC1_2, CUSTOM_VEC1_3, CUSTOM_VEC1_4, 
		CUSTOM_VEC2_0, CUSTOM_VEC2_1, CUSTOM_VEC2_2, CUSTOM_VEC2_3, CUSTOM_VEC2_4, 
		CUSTOM_VEC3_0, CUSTOM_VEC3_1, CUSTOM_VEC3_2, CUSTOM_VEC3_3, CUSTOM_VEC3_4, 
		CUSTOM_VEC4_0, CUSTOM_VEC4_1, CUSTOM_VEC4_2, CUSTOM_VEC4_3, CUSTOM_VEC4_4,
		CUSTOM_MATERIAL_VEC1_0, CUSTOM_MATERIAL_VEC1_1, CUSTOM_MATERIAL_VEC1_2, CUSTOM_MATERIAL_VEC1_3, CUSTOM_MATERIAL_VEC1_4,
		CUSTOM_MATERIAL_VEC2_0, CUSTOM_MATERIAL_VEC2_1, CUSTOM_MATERIAL_VEC2_2, CUSTOM_MATERIAL_VEC2_3, CUSTOM_MATERIAL_VEC2_4,
		CUSTOM_MATERIAL_VEC3_0, CUSTOM_MATERIAL_VEC3_1, CUSTOM_MATERIAL_VEC3_2, CUSTOM_MATERIAL_VEC3_3, CUSTOM_MATERIAL_VEC3_4,
		CUSTOM_MATERIAL_VEC4_0, CUSTOM_MATERIAL_VEC4_1, CUSTOM_MATERIAL_VEC4_2, CUSTOM_MATERIAL_VEC4_3, CUSTOM_MATERIAL_VEC4_4
	};
	
	enum class CAMERA_VECTOR {
		UP_VECTOR, GAZE_VECTOR, RIGHT_VECTOR
	};

	enum class BIND_TEXTURE_TARGET : unsigned int {
		TEXTURE_1D = GL_TEXTURE_1D, TEXTURE_2D = GL_TEXTURE_2D, TEXTURE_3D = GL_TEXTURE_3D, TEXTURE_1D_ARRAY = GL_TEXTURE_1D_ARRAY, TEXTURE_2D_ARRAY = GL_TEXTURE_2D_ARRAY, TEXTURE_RECTANGLE = GL_TEXTURE_RECTANGLE, TEXTURE_CUBE_MAP = GL_TEXTURE_CUBE_MAP, TEXTURE_CUBE_MAP_ARRAY = GL_TEXTURE_CUBE_MAP_ARRAY, TEXTURE_BUFFER = GL_TEXTURE_BUFFER, TEXTURE_2D_MULTISAMPLE = GL_TEXTURE_2D_MULTISAMPLE, TEXTURE_2D_MULTISAMPLE_ARRAY = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	};

	enum class TEXTURE_PARAMETER_TARGET : unsigned int {
		TEXTURE_1D = GL_TEXTURE_1D, TEXTURE_1D_ARRAY = GL_TEXTURE_1D_ARRAY, TEXTURE_2D = GL_TEXTURE_2D, TEXTURE_2D_ARRAY = GL_TEXTURE_2D_ARRAY, TEXTURE_2D_MULTISAMPLE = GL_TEXTURE_2D_MULTISAMPLE, TEXTURE_2D_MULTISAMPLE_ARRAY = GL_TEXTURE_2D_MULTISAMPLE_ARRAY, TEXTURE_3D = GL_TEXTURE_3D, TEXTURE_CUBE_MAP = GL_TEXTURE_CUBE_MAP, TEXTURE_CUBE_MAP_ARRAY = GL_TEXTURE_CUBE_MAP_ARRAY, TEXTURE_RECTANGLE = GL_TEXTURE_RECTANGLE
	};

	enum class TEXTURE_PARAMETER_NAME : unsigned int {
		DEPTH_STENCIL_TEXTURE_MODE = GL_DEPTH_STENCIL_TEXTURE_MODE, TEXTURE_BASE_LEVEL = GL_TEXTURE_BASE_LEVEL, TEXTURE_COMPARE_FUNC = GL_TEXTURE_COMPARE_FUNC, TEXTURE_COMPARE_MODE = GL_TEXTURE_COMPARE_MODE, TEXTURE_LOD_BIAS = GL_TEXTURE_LOD_BIAS, TEXTURE_MIN_FILTER = GL_TEXTURE_MIN_FILTER, TEXTURE_MAG_FILTER = GL_TEXTURE_MAG_FILTER, TEXTURE_MIN_LOD = GL_TEXTURE_MIN_LOD, TEXTURE_MAX_LOD = GL_TEXTURE_MAX_LOD, TEXTURE_MAX_LEVEL = GL_TEXTURE_MAX_LEVEL, TEXTURE_SWIZZLE_R = GL_TEXTURE_SWIZZLE_R, TEXTURE_SWIZZLE_G = GL_TEXTURE_SWIZZLE_G, TEXTURE_SWIZZLE_B = GL_TEXTURE_SWIZZLE_B, TEXTURE_SWIZZLE_A = GL_TEXTURE_SWIZZLE_A, TEXTURE_WRAP_S = GL_TEXTURE_WRAP_S, TEXTURE_WRAP_T = GL_TEXTURE_WRAP_T, TEXTURE_WRAP_R = GL_TEXTURE_WRAP_R, TEXTURE_BORDER_COLOR = GL_TEXTURE_BORDER_COLOR, TEXTURE_SWIZZLE_RGBA = GL_TEXTURE_SWIZZLE_RGBA
	};

	enum class PIXEL_STORE_NAME : unsigned int {
		PACK_SWAP_BYTES = GL_PACK_SWAP_BYTES, PACK_LSB_FIRST = GL_PACK_LSB_FIRST, PACK_ROW_LENGTH = GL_PACK_ROW_LENGTH, PACK_IMAGE_HEIGHT = GL_PACK_IMAGE_HEIGHT, PACK_SKIP_PIXELS = GL_PACK_SKIP_PIXELS, PACK_SKIP_ROWS = GL_PACK_SKIP_ROWS, PACK_SKIP_IMAGES = GL_PACK_SKIP_IMAGES, PACK_ALIGNMENT = GL_PACK_ALIGNMENT, UNPACK_SWAP_BYTES = GL_UNPACK_SWAP_BYTES, UNPACK_LSB_FIRST = GL_UNPACK_LSB_FIRST, UNPACK_ROW_LENGTH = GL_UNPACK_ROW_LENGTH, UNPACK_IMAGE_HEIGHT = GL_UNPACK_IMAGE_HEIGHT, UNPACK_SKIP_PIXELS = GL_UNPACK_SKIP_PIXELS, UNPACK_SKIP_ROWS = GL_UNPACK_SKIP_ROWS, UNPACK_SKIP_IMAGES = GL_UNPACK_SKIP_IMAGES, UNPACK_ALIGNMENT =  GL_UNPACK_ALIGNMENT
	};

	enum class BIND_BUFFER_TARGET : unsigned int {
		//TODO: implement this
	};

	enum class VERTEX_ATTRIB_POINTER_TYPE : unsigned int {
		//TODO: implement this
	};

	enum class BIND_FRAMEBUFFER_TARGET : unsigned int {
		//TODO: implement this
	};

	enum class READ_PIXEL_FORMAT : unsigned int {
		//TODO: implement this
	};

	enum class READ_PIXEL_TYPE : unsigned int {
		//TODO: implement this
	};

	enum class ENABLE_CAPACITY : unsigned int {
		//TODO: implement this
	};

	enum class DRAW_ARRAY_MODE : unsigned int {
		//TODO: implement this
	};

	enum class DRAW_ELEMENT_MODE : unsigned int {
		//TODO: implement this
	};

	enum class CREATE_SHADER_TYPE : unsigned int {
		//TODO: implement this
	};

	enum class TEXTURE_IMAGE_2D_TARGET : unsigned int {
		TEXTURE_2D = GL_TEXTURE_2D, PROXY_TEXTURE_2D = GL_PROXY_TEXTURE_2D, TEXTURE_1D_ARRAY = GL_TEXTURE_1D_ARRAY, PROXY_TEXTURE_1D_ARRAY = GL_PROXY_TEXTURE_1D_ARRAY, TEXTURE_RECTANGLE = GL_TEXTURE_RECTANGLE, PROXY_TEXTURE_RECTANGLE = GL_PROXY_TEXTURE_RECTANGLE, TEXTURE_CUBE_MAP_POSITIVE_X = GL_TEXTURE_CUBE_MAP_POSITIVE_X, TEXTURE_CUBE_MAP_NEGATIVE_X = GL_TEXTURE_CUBE_MAP_NEGATIVE_X, TEXTURE_CUBE_MAP_POSITIVE_Y = GL_TEXTURE_CUBE_MAP_POSITIVE_Y, TEXTURE_CUBE_MAP_NEGATIVE_Y = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, TEXTURE_CUBE_MAP_POSITIVE_Z = GL_TEXTURE_CUBE_MAP_POSITIVE_Z, TEXTURE_CUBE_MAP_NEGATIVE_Z = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, PROXY_TEXTURE_CUBE_MAP = GL_PROXY_TEXTURE_CUBE_MAP
	};

	enum class TEXTURE_IMAGE_2D_FORMAT : unsigned int {
		RED = GL_RED, RG = GL_RG, RGB = GL_RGB, BGR = GL_BGR, RGBA = GL_RGBA, BGRA = GL_BGRA, RED_INTEGER = GL_RED_INTEGER, RG_INTEGER = GL_RG_INTEGER, RGB_INTEGER = GL_RGB_INTEGER, BGR_INTEGER = GL_BGR_INTEGER, RGBA_INTEGER = GL_RGBA_INTEGER, BGRA_INTEGER = GL_BGRA_INTEGER, STENCIL_INDEX = GL_STENCIL_INDEX, DEPTH_COMPONENT = GL_DEPTH_COMPONENT, DEPTH_STENCIL = GL_DEPTH_STENCIL
	};

	enum class TEXTURE_IMAGE_2D_INTERNAL_FORMAT: int {
		DEPTH_COMPONENT = GL_DEPTH_COMPONENT, DEPTH_STENCIL = GL_DEPTH_STENCIL, RED = GL_RED, RG = GL_RG, RGB = GL_RGB, RGBA = GL_RGBA,
		R8 = GL_R8, R8_SNORM = GL_R8_SNORM, R16 = GL_R16, R16_SNORM = GL_R16_SNORM, RG8 = GL_RG8, RG8_SNORM = GL_RG8_SNORM, RG16 = GL_RG16, RG16_SNORM = GL_RG16_SNORM, R3_G3_B2 = GL_R3_G3_B2, RGB4 = GL_RGB4, RGB5 = GL_RGB5, RGB8 = GL_RGB8, RGB8_SNORM = GL_RGB8_SNORM, RGB10 = GL_RGB10, RGB12 = GL_RGB12, RGB16_SNORM = GL_RGB16_SNORM, RGBA2 = GL_RGBA2, RGBA4 = GL_RGBA4, RGB5_A1 = GL_RGB5_A1, RGBA8 = GL_RGBA8, RGBA8_SNORM = GL_RGBA8_SNORM, RGB10_A2 = GL_RGB10_A2, RGB10_A2UI = GL_RGB10_A2UI, RGBA12 = GL_RGBA12, RGBA16 = GL_RGBA16, SRGB8 = GL_SRGB8, SRGB8_ALPHA8 = GL_SRGB8_ALPHA8, R16F = GL_R16F, RG16F = GL_RG16F, RGB16F = GL_RGB16F, RGBA16F = GL_RGBA16F, R32F = GL_R32F, RG32F = GL_RG32F, RGB32F = GL_RGB32F, RGBA32F = GL_RGBA32F, R11F_G11F_B10F = GL_R11F_G11F_B10F, RGB9_E5 = GL_RGB9_E5, R8I = GL_R8I, R8UI = GL_R8UI, R16I = GL_R16I, R16UI = GL_R16UI, R32I = GL_R32I, R32UI = GL_R32UI, RG8I = GL_RG8I, RG8UI = GL_RG8UI, RG16I = GL_RG16I, RG16UI = GL_RG16UI, RG32I = GL_RG32I, RG32UI = GL_RG32UI, RGB8I = GL_RGB8I, RGB8UI = GL_RGB8UI, RGB16I = GL_RGB16I, RGB16UI = GL_RGB16UI, RGB32I = GL_RGB32I, RGB32UI = GL_RGB32UI, RGBA8I = GL_RGBA8I, RGBA8UI = GL_RGBA8UI, RGBA16I = GL_RGBA16I, RGBA16UI = GL_RGBA16UI, RGBA32I = GL_RGBA32I, RGBA32UI = GL_RGBA32UI,
		COMPRESSED_RED = GL_COMPRESSED_RED, COMPRESSED_RG = GL_COMPRESSED_RG, COMPRESSED_RGB = GL_COMPRESSED_RGB, COMPRESSED_RGBA = GL_COMPRESSED_RGBA, COMPRESSED_SRGB = GL_COMPRESSED_SRGB, COMPRESSED_SRGB_ALPHA = GL_COMPRESSED_SRGB_ALPHA, COMPRESSED_RED_RGTC1 = GL_COMPRESSED_RED_RGTC1, COMPRESSED_SIGNED_RED_RGTC1 = GL_COMPRESSED_SIGNED_RED_RGTC1, COMPRESSED_RG_RGTC2 = GL_COMPRESSED_RG_RGTC2, COMPRESSED_SIGNED_RG_RGTC2 = GL_COMPRESSED_SIGNED_RG_RGTC2, COMPRESSED_RGBA_BPTC_UNORM = GL_COMPRESSED_RGBA_BPTC_UNORM, COMPRESSED_SRGB_ALPHA_BPTC_UNORM = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM, COMPRESSED_RGB_BPTC_SIGNED_FLOAT = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT, COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	};

	enum class TEXTURE_IMAGE_2D_TYPE: unsigned int {
		UNSIGNED_BYTE = GL_UNSIGNED_BYTE, BYTE = GL_BYTE, UNSIGNED_SHORT = GL_UNSIGNED_SHORT, SHORT = GL_SHORT, UNSIGNED_INT = GL_UNSIGNED_INT, INT = GL_INT, HALF_FLOAT = GL_HALF_FLOAT, FLOAT = GL_FLOAT, UNSIGNED_BYTE_3_3_2 = GL_UNSIGNED_BYTE_3_3_2, UNSIGNED_BYTE_2_3_3_REV = GL_UNSIGNED_BYTE_2_3_3_REV, UNSIGNED_SHORT_5_6_5 = GL_UNSIGNED_SHORT_5_6_5, UNSIGNED_SHORT_5_6_5_REV = GL_UNSIGNED_SHORT_5_6_5_REV, UNSIGNED_SHORT_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4, UNSIGNED_SHORT_4_4_4_4_REV = GL_UNSIGNED_SHORT_4_4_4_4_REV, UNSIGNED_SHORT_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1, UNSIGNED_SHORT_1_5_5_5_REV = GL_UNSIGNED_SHORT_1_5_5_5_REV, UNSIGNED_INT_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8, UNSIGNED_INT_8_8_8_8_REV = GL_UNSIGNED_INT_8_8_8_8_REV, UNSIGNED_INT_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2, UNSIGNED_INT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV
	};

	/// <summary>
	/// Returns the default value of a color.
	/// </summary>
	/// <param name="c"> Color c. </param>
	/// <returns> Default value of c.</returns>
	glm::vec3 GetColor(const COLOR c);

	/// <summary>
	/// Returns how many elements an attribute has.
	/// </summary>
	/// <param name="type"> Type of the attribute. </param>
	/// <returns> how many elements an attribute of type has. </returns>
	unsigned int AttributeElementCount(const ATTRIBUTE_TYPE type);

	/// <summary>
	/// Returns how many total elements a group of attribute have.
	/// </summary>
	/// <param name="types"> Types of attributes. </param>
	/// <returns> how many total elements a group of attributes of types have. </returns>
	unsigned int AttributeElementCount(const std::vector<ATTRIBUTE_TYPE> types);

	/// <summary>
	/// Returns whether the given attribute is inherent to materials or not.
	/// </summary>
	/// <param name="type"> The given attribute type.</param>
	/// <returns> Whether the given attribute is inherent to materials.</returns>
	bool IsMaterialAttribute(const ATTRIBUTE_TYPE type);

	/// <summary>
	/// Returns whether the given attribute is inherent to vertices or not.
	/// </summary>
	/// <param name="type"> The given attribute type.</param>
	/// <returns> Whether the given attribute is inherent to vertices.</returns>
	bool IsVertexAttribute(const ATTRIBUTE_TYPE type);

	/// <summary>
	/// Returns whether the given attribute is a user defined attribute or not.
	/// </summary>
	/// <param name="type"> The given attribute type.</param>
	/// <returns> Whether the given attribute is a user defined attribute.</returns>
	bool IsCustomAttribute(const ATTRIBUTE_TYPE type);

	/// <summary>
	/// Returns index of the given custom attribute.
	/// </summary>
	/// <param name="type"> The given attribute type.</param>
	/// <returns> Index of the given custom attribute.</returns>
	unsigned int CustomAttributeIndex(const ATTRIBUTE_TYPE type);

	/// <summary>
	/// Radian to degree conversion.
	/// </summary>
	/// <param name="rad"> Radian.</param>
	/// <returns> Radians degree equivalent.</returns>
	float Degree(const float rad);

	/// <summary>
	/// Creates a combination of three different rotations, one in each axis.
	/// </summary>
	/// <param name="rot"> Rotation in x, y, and z axis.</param>
	/// <returns> Rotation matrix created from given information.</returns>
	glm::mat4 RotationMatrix(const glm::vec3 rot);

	/// <summary>
	/// Transforms the given point using the given transformation matrix.
	/// </summary>
	/// <param name="point"> Original point.</param>
	/// <param name="transformation"> Transformation matrix.</param>
	/// <returns> Resulting point.</returns>
	glm::vec3 TransformPoint(const glm::vec3 point, const glm::mat4 transformation);

	/// <summary>
	/// Transforms the given normal using the given transformation matrix.
	/// </summary>
	/// <param name="point"> Original normal.</param>
	/// <param name="transformation"> Transformation matrix.</param>
	/// <returns> Resulting normal.</returns>
	glm::vec3 TransformNormal(const glm::vec3 normal, const glm::mat4 transformation);

	std::vector<std::string> Tokenize(const std::string s, const std::string token = " ");

	std::vector<int> TokenizeAsInteger(const std::string s, const std::string token = " ");

	std::vector<float> TokenizeAsFloat(const std::string s, const std::string token = " ");

	bool CompareWithoutCase(char first, char second);

	bool CompareWithoutCase(std::string first, std::string second);

	glm::vec3 GetSurfaceNormal(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);

	bool IsComplete(glm::ivec3 v1);
}

#include "BasicTypes.inl"

#endif