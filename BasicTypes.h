#ifndef FAGL_BASIC_TYPES_H
#define FAGL_BASIC_TYPES_H

#include "FAGL.h"

namespace fagl {
	

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