#include "BasicTypes.h"
namespace fagl {
	using glm::mat4;
	using glm::vec4;
	using glm::vec3;

	using std::vector;
	using std::string;

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

	vec3 GetColor(const COLOR c) {
		switch (c)
		{
		case COLOR::WHITE:
			return vec3(255.0f, 255.0f, 255.0f);
		case COLOR::SILVER:
			return vec3(192.0f, 192.0f, 192.0f);
		case COLOR::GRAY:
			return vec3(128.0f, 128.0f, 128.0f);
		case COLOR::BLACK:
			return vec3(0.0f, 0.0f, 0.0f);
		case COLOR::RED:
			return vec3(255.0f, 0.0f, 0.0f);
		case COLOR::MAROON:
			return vec3(128.0f, 0.0f, 0.0f);
		case COLOR::YELLOW:
			return vec3(255.0f, 255.0f, 0.0f);
		case COLOR::OLIVE:
			return vec3(128.0f, 128.0f, 0.0f);
		case COLOR::LIME:
			return vec3(0.0f, 255.0f, 0.0f);
		case COLOR::GREEN:
			return vec3(0.0f, 128.0f, 0.0f);
		case COLOR::AQUA:
			return vec3(0.0f, 255.0f, 255.0f);
		case COLOR::TEAL:
			return vec3(0.0f, 128.0f, 128.0f);
		case COLOR::BLUE:
			return vec3(0.0f, 0.0f, 255.0f);
		case COLOR::NAVY:
			return vec3(0.0f, 0.0f, 128.0f);
		case COLOR::FUCHSIA:
			return vec3(255.0f, 0.0f, 255.0f);
		case COLOR::PURPLE:
			return vec3(128.0f, 0.0f, 128.0f);
		default:
			return vec3(0.0f, 0.0f, 0.0f);
		}
	}

	unsigned int AttributeElementCount(const ATTRIBUTE_TYPE type) {
		switch (type) {
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_4:
		case ATTRIBUTE_TYPE::SPECULAR_COLOR:
		case ATTRIBUTE_TYPE::TRANSPERANCY:
			return 4;
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_4:
		case ATTRIBUTE_TYPE::POSITION:
		case ATTRIBUTE_TYPE::NORMAL:
		case ATTRIBUTE_TYPE::AMBIENT_COLOR:
		case ATTRIBUTE_TYPE::DIFFUSE_COLOR:
			return 3;
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_4:
		case ATTRIBUTE_TYPE::TEXTURE:
			return 2;
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_4:
		case ATTRIBUTE_TYPE::DENSITY:
		case ATTRIBUTE_TYPE::ILLUMINATION_MODEL:
			return 1;
		default:
			return 0;
		}
	}
	unsigned int AttributeElementCount(const std::vector<ATTRIBUTE_TYPE> types)
	{
		unsigned int retval = 0;
		for (ATTRIBUTE_TYPE type : types) {
			retval += AttributeElementCount(type);
		}
		return retval;
	}
	bool IsMaterialAttribute(const ATTRIBUTE_TYPE type)
	{
		switch (type) {
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_4:
		case ATTRIBUTE_TYPE::SPECULAR_COLOR:
		case ATTRIBUTE_TYPE::TRANSPERANCY:
		case ATTRIBUTE_TYPE::AMBIENT_COLOR:
		case ATTRIBUTE_TYPE::DIFFUSE_COLOR:
		case ATTRIBUTE_TYPE::DENSITY:
		case ATTRIBUTE_TYPE::ILLUMINATION_MODEL:
			return true;
		default:
			return false;
		}
	}
	bool IsVertexAttribute(const ATTRIBUTE_TYPE type)
	{
		switch (type) {
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_4:
		case ATTRIBUTE_TYPE::POSITION:
		case ATTRIBUTE_TYPE::NORMAL:
		case ATTRIBUTE_TYPE::TEXTURE:
			return true;
		default:
			return false;
		}
	}
	bool IsCustomAttribute(const ATTRIBUTE_TYPE type)
	{
		switch (type) {
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_0:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_0:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_4:
			return true;
		default:
			return false;
		}
	}
	unsigned int CustomAttributeIndex(const ATTRIBUTE_TYPE type)
	{
		switch (type) {
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_4:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_4:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_4:
			return 4;
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_3:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_3:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_3:
			return 3;
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_2:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_2:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_2:
			return 2;
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC4_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC3_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC2_1:
		case ATTRIBUTE_TYPE::CUSTOM_MATERIAL_VEC1_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC4_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC3_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC2_1:
		case ATTRIBUTE_TYPE::CUSTOM_VEC1_1:
			return 1;
		default:
			return 0;
		}
	}
	float Degree(const float rad)
	{
		return (float)((rad / 180.0f) * M_PI);
	}
	glm::mat4 RotationMatrix(const glm::vec3 rot)
	{
		mat4 rotX = glm::rotate<float>(mat4(1.0f), Degree(rot.x), vec3(1.0f, 0.0f, 0.0f));
		mat4 rotY = glm::rotate<float>(mat4(1.0f), Degree(rot.y), vec3(0.0f, 1.0f, 0.0f));
		mat4 rotZ = glm::rotate<float>(mat4(1.0f), Degree(rot.z), vec3(0.0f, 0.0f, 1.0f));

		return rotZ * rotY * rotX;
	}

	vec3 TransformPoint(const vec3 point, const mat4 transformation)
	{
		return vec3(transformation * vec4(point, 1.0f));
	}

	glm::vec3 TransformNormal(const glm::vec3 normal, const glm::mat4 transformation)
	{
		return glm::inverse(glm::transpose(glm::mat3(transformation))) * normal;
	}

	vector<std::string> Tokenize(const string s, const string token)
	{
		vector<string> elements;
		string temp;

		for (int i = 0; i < int(s.size()); i++)
		{
			string test = s.substr(i, token.size());

			if (test == token)
			{
				if (!temp.empty())
				{
					elements.push_back(temp);
					temp.clear();
					i += (int)token.size() - 1;
				}
				else
				{
					elements.push_back("");
				}
			}
			else if (i + token.size() >= s.size())
			{
				temp += s.substr(i, token.size());
				elements.push_back(temp);
				break;
			}
			else
			{
				temp += s[i];
			}
		}
		return elements;
	}

	vector<int> TokenizeAsInteger(const string s, const string token)
	{
		vector<string> temp = Tokenize(s, token);
		vector<int> retVal;
		for (unsigned int i = 0; i < temp.size(); i++) {
			if (temp[i] != "") {
				retVal.push_back(stoi(temp[i]));
			}
			else {
				retVal.push_back(0);
			}
		}
		return retVal;
	}
	vector<float> TokenizeAsFloat(const string s, const string token)
	{
		vector<string> temp = Tokenize(s, token);
		vector<float> retVal;
		for (unsigned int i = 0; i < temp.size(); i++) {
			if (temp[i] != "") {
				retVal.push_back(stof(temp[i]));
			}
			else {
				retVal.push_back(0.0f);
			}
		}
		return retVal;
	}

	bool CompareWithoutCase(char first, char second)
	{
		if (isupper(second)) {
			return first == second || first == second - 32;
		}
		else if (islower(second)) {
			return first == second || first == second + 32;
		}
		else {
			return first == second;
		}
	}

	bool CompareWithoutCase(std::string first, std::string second)
	{
		if (first.length() < second.length()) {
			return false;
		}
		for (unsigned int i = 0; i < second.length(); i++) {
			if (!CompareWithoutCase(first[i], second[i])) {
				return false;
			}
		}
		return true;
	}

	glm::vec3 GetSurfaceNormal(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3)
	{
		return glm::vec3();
	}

	bool IsComplete(glm::ivec3 v1)
	{
		return v1.x >= 0 && v1.y >= 0 && v1.z >= 0;
	}

}