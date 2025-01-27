#ifndef FAGL_ATTRIBUTE_CONTAINER_H
#define FAGL_ATTRIBUTE_CONTAINER_H

#include "FAGL.h"
#include "BasicTypes.h"

namespace fagl {
	class AttributeContainer {
	protected:
		glm::vec4 custom_vec4[5] = { glm::vec4(), glm::vec4(), glm::vec4(), glm::vec4(), glm::vec4() };
		glm::vec3 custom_vec3[5] = { glm::vec3(), glm::vec3(), glm::vec3(), glm::vec3(), glm::vec3() };
		glm::vec2 custom_vec2[5] = { glm::vec2(), glm::vec2(), glm::vec2(), glm::vec2(), glm::vec2() };
		glm::vec1 custom_vec1[5] = { glm::vec1(), glm::vec1(), glm::vec1(), glm::vec1(), glm::vec1() };
	public:

		/// <summary>
		/// Get function for custom attributes that are vec4. 
		/// </summary>
		/// <param name="i"> index of the custom attribute. </param>
		/// <returns> Value of ATTRIBUTE_TYPE::CUSTOM(_MATERIAL)_VEC4_i. </returns>
		inline glm::vec4 GetCustom4(const unsigned int i) const { return custom_vec4[i]; }

		/// <summary>
		/// Get function for custom attributes that are vec3. 
		/// </summary>
		/// <param name="i"> index of the custom attribute. </param>
		/// <returns> Value of ATTRIBUTE_TYPE::CUSTOM(_MATERIAL)_VEC3_i. </returns>
		inline glm::vec3 GetCustom3(const unsigned int i) const { return custom_vec3[i]; }

		/// <summary>
		/// Get function for custom attributes that are vec2. 
		/// </summary>
		/// <param name="i"> index of the custom attribute. </param>
		/// <returns> Value of ATTRIBUTE_TYPE::CUSTOM(_MATERIAL)_VEC2_i. </returns>
		inline glm::vec2 GetCustom2(const unsigned int i) const { return custom_vec2[i]; }

		/// <summary>
		/// Get function for custom attributes that are vec1. 
		/// </summary>
		/// <param name="i"> index of the custom attribute. </param>
		/// <returns> Value of ATTRIBUTE_TYPE::CUSTOM(_MATERIAL)_VEC1_i. </returns>
		inline glm::vec1 GetCustom1(const unsigned int i) const { return custom_vec1[i]; }

		/// <summary>
		/// Get function for attributes that are vec1. 
		/// </summary>
		/// <param name="type"> Type of the attribute. </param>
		/// <returns> Value of the Attribute. </returns>
		inline virtual glm::vec1 GetAttribute1(const ATTRIBUTE_TYPE type) const { return glm::vec1(); }

		/// <summary>
		/// Get function for attributes that are vec2. 
		/// </summary>
		/// <param name="type"> Type of the attribute. </param>
		/// <returns> Value of the Attribute. </returns>
		inline virtual glm::vec2 GetAttribute2(const ATTRIBUTE_TYPE type) const { return glm::vec2(); }

		/// <summary>
		/// Get function for attributes that are vec3. 
		/// </summary>
		/// <param name="type"> Type of the attribute. </param>
		/// <returns> Value of the Attribute. </returns>
		inline virtual glm::vec3 GetAttribute3(const ATTRIBUTE_TYPE type) const { return glm::vec3(); }

		/// <summary>
		/// Get function for attributes that are vec4. 
		/// </summary>
		/// <param name="type"> Type of the attribute. </param>
		/// <returns> Value of the Attribute. </returns>
		inline virtual glm::vec4 GetAttribute4(const ATTRIBUTE_TYPE type) const { return glm::vec4(); }

		/// <summary>
		/// Get function for attributes. 
		/// </summary>
		/// <param name="type"> Type of the attribute. </param>
		/// <returns> Value of the Attribute. </returns>
		inline virtual glm::vec4 GetAttribute(const ATTRIBUTE_TYPE type) const {
			unsigned int size = AttributeElementCount(type);
			switch (size) {
			case 4:
				return glm::vec4(GetAttribute4(type));
			case 3:
				return glm::vec4(GetAttribute3(type), 0);
			case 2:
				return glm::vec4(GetAttribute2(type), 0, 0);
			case 1:
				return glm::vec4(GetAttribute1(type), 0, 0, 0);
			default:
				return glm::vec4();
			}
		}

		/// <summary>
		/// Set function for custom attributes that are vec4. 
		/// </summary>
		/// <param name="i"> Index of the custom attribute. </param>
		/// <param name="value"> New value of ATTRIBUTE_TYPE::CUSTOM(_MATERIAL)_VEC4_i.</param>
		inline void SetCustom4(const unsigned int i, glm::vec4 value) { custom_vec4[i] = glm::vec4(value); }

		/// <summary>
		/// Set function for custom attributes that are vec3. 
		/// </summary>
		/// <param name="i"> Index of the custom attribute. </param>
		/// <param name="value"> New value of ATTRIBUTE_TYPE::CUSTOM(_MATERIAL)_VEC3_i.</param>
		inline void SetCustom3(const unsigned int i, glm::vec3 value) { custom_vec3[i] = glm::vec3(value); }

		/// <summary>
		/// Set function for custom attributes that are vec2. 
		/// </summary>
		/// <param name="i"> Index of the custom attribute. </param>
		/// <param name="value"> New value of ATTRIBUTE_TYPE::CUSTOM(_MATERIAL)_VEC2_i.</param>
		inline void SetCustom2(const unsigned int i, glm::vec2 value) { custom_vec2[i] = glm::vec2(value); }

		/// <summary>
		/// Set function for custom attributes that are vec1. 
		/// </summary>
		/// <param name="i"> Index of the custom attribute. </param>
		/// <param name="value"> New value of ATTRIBUTE_TYPE::CUSTOM(_MATERIAL)_VEC1_i.</param>
		inline void SetCustom1(const unsigned int i, glm::vec1 value) { custom_vec1[i] = glm::vec1(value); }
	};
}

#endif
