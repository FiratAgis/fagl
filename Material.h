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
		/// Returns the ka of the material, or its AMBIENT_COLOR attribute.
		/// </summary>
		/// <returns> Ambient color coefficient.</returns>
		glm::vec3 GetAmbient() const;

		/// <summary>
		/// Returns the kd of the material, or its DIFFUSE_COLOR attribute.
		/// </summary>
		/// <returns> Diffuse color coefficient.</returns>
		glm::vec3 GetDiffuse() const;

		/// <summary>
		/// Returns the ks and ns of the material, or its SPECULAR_COLOR attribute.
		/// </summary>
		/// <returns> Specular color coefficient as xyz and Phong exponent as w.</returns>
		glm::vec4 GetSpecular() const;

		/// <summary>
		/// Returns the tf and tr of the material, or its TRANSPERANCY attribute.
		/// </summary>
		/// <returns> Transmission color filter as xyz and transparency as w.</returns>
		glm::vec4 GetTransperancy() const;

		/// <summary>
		/// Returns ni of the material, or its DENSITY attribute.
		/// </summary>
		/// <returns> Density.</returns>
		float GetDensity() const;

		/// <summary>
		/// Returns illum of the material, or its ILLUMINATION_MODEL attribute.
		/// </summary>
		/// <returns> Illumination model.</returns>
		int GetIlluminationModel() const;

		/// <summary>
		/// Returns the value of an attribute that has one element.
		/// </summary>
		/// <param name="type"> Type of the attribute.</param>
		/// <returns> Value of the attribute.</returns>
		glm::vec1 GetAttribute1(const ATTRIBUTE_TYPE type) const;

		/// <summary>
		/// Returns the value of an attribute that has two elements.
		/// </summary>
		/// <param name="type"> Type of the attribute.</param>
		/// <returns> Value of the attribute.</returns>
		glm::vec2 GetAttribute2(const ATTRIBUTE_TYPE type) const;

		/// <summary>
		/// Returns the value of an attribute that has three elements.
		/// </summary>
		/// <param name="type"> Type of the attribute.</param>
		/// <returns> Value of the attribute.</returns>
		glm::vec3 GetAttribute3(const ATTRIBUTE_TYPE type) const;

		/// <summary>
		/// Returns the value of an attribute that has four elements.
		/// </summary>
		/// <param name="type"> Type of the attribute.</param>
		/// <returns> Value of the attribute.</returns>
		glm::vec4 GetAttribute4(const ATTRIBUTE_TYPE type) const;

		/// <summary>
		/// Returns the value of an attribute.
		/// </summary>
		/// <param name="type"> Type of the attribute.</param>
		/// <returns> Value of the attribute.</returns>
		glm::vec4 GetAttribute(const ATTRIBUTE_TYPE type) const;

	};

	std::vector<Material> ReadMaterialFile(const std::string& filename);
}

#include "Material.inl"

#endif