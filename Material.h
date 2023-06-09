#ifndef FAGL_MATERIAL_H
#define FAGL_MATERIAL_H

#include "AttributeContainer.h"

namespace fagl {
	
	class Material : public AttributeContainer {

	protected:
		std::string name;
		glm::vec3 ka;
		glm::vec3 kd;
		glm::vec3 ks;
		float ns;
		float tr;
		glm::vec3 tf;
		float ni;
		int illum;

	public:
		/// <summary>
		/// Create Material from .mtl file snippet.
		/// </summary>
		/// <param name="materialFileContent"> Material file snippet.</param>
		Material(const std::string& materialFileContent);

		/// <summary>
		/// Copy constructor for Materials.
		/// </summary>
		/// <param name="m"> Material to be copied.</param>
		Material(const Material& m);

		Material(const std::string& material_name, const glm::vec3 material_ka, const glm::vec3 material_kd, const glm::vec3 material_ks, const float material_ns, const float material_tr, const glm::vec3 material_tf, const float material_ni, const int material_illum);
		
		Material();

		/// <summary>
		/// Returns the name of the material.
		/// </summary>
		/// <returns> Name of the material.</returns>
		std::string GetName() const;

		/// <summary>
		/// Returns the ka of the material, or AMBIENT_COLOR attribute.
		/// </summary>
		/// <returns> Ambient color coefficient.</returns>
		glm::vec3 GetAmbient() const;

		/// <summary>
		/// Returns the kd of the material, or AMBIANT_COLOR attribute.
		/// </summary>
		/// <returns> Ambient color coefficient.</returns>
		glm::vec3 GetDiffuse() const;

		glm::vec4 GetSpecular() const;

		glm::vec4 GetTransperancy() const;

		float GetDensity() const;
		int GetIlluminationModel() const;

		glm::vec1 GetAttribute1(const ATTRIBUTE_TYPE type) const;

		glm::vec2 GetAttribute2(const ATTRIBUTE_TYPE type) const {
			if (IsCustomAttribute(type)) {
				return GetCustom2(CustomAttributeIndex(type));
			}
			return glm::vec2();
		}
		glm::vec3 GetAttribute3(const ATTRIBUTE_TYPE type) const {
			if (IsCustomAttribute(type)) {
				return GetCustom3(CustomAttributeIndex(type));
			}
			switch (type)
			{
				case ATTRIBUTE_TYPE::AMBIENT_COLOR:
					return GetAmbient();
				case ATTRIBUTE_TYPE::DIFFUSE_COLOR:
					return GetDiffuse();
				default:
					return glm::vec3();
			}
		}
		glm::vec4 GetAttribute4(const ATTRIBUTE_TYPE type) const {
			if (IsCustomAttribute(type)) {
				return GetCustom4(CustomAttributeIndex(type));
			}
			switch (type) {
				case ATTRIBUTE_TYPE::SPECULAR_COLOR:
					return GetSpecular();
				case ATTRIBUTE_TYPE::TRANSPERANCY:
					return GetTransperancy();
				default:
					return glm::vec4();
			}
		}
		glm::vec4 GetAttribute(const ATTRIBUTE_TYPE type) const {
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
	};

	std::vector<Material> ReadMaterialFile(const std::string& filename);
}

#include "Material.inl"

#endif