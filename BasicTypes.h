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

	bool IsMaterialAttribute(const ATTRIBUTE_TYPE type);
	bool IsVertexAttribute(const ATTRIBUTE_TYPE type);
	bool IsCustomAttribute(const ATTRIBUTE_TYPE type);
	unsigned int CustomAttributeIndex(const ATTRIBUTE_TYPE type);

	float Degree(const float rad);

	glm::mat4 RotationMatrix(const glm::vec3 rot);

	glm::vec3 TransformPoint(const glm::vec3 point, const glm::mat4 transformation);

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