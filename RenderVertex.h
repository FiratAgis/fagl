#ifndef FAGL_RENDER_VERTEX_H
#define FAGL_RENDER_VERTEX_H

#include "Material.h"

namespace fagl {
	
	class RenderVertex : public AttributeContainer {
	protected:
		Material mat;
		glm::vec3 pos;
		glm::vec3 norm;
		glm::vec2 text;
	public:


		RenderVertex(const glm::vec3 position = glm::vec3(0, 0, 0), const glm::vec3 normal = glm::vec3(0, 0, 0), const glm::vec2 texture = glm::vec2(0, 0), const Material material = Material()) : pos(position), norm(normal), text(texture), mat(material) { }
		RenderVertex(const RenderVertex& r) : pos(r.GetPosition()), norm(r.GetNormal()), text(r.GetTextureCoordinate()), mat(r.GetMaterial()) {
			for (unsigned int i = 0; i < 5; i++) {
				SetCustom1(i, r.GetCustom1(i));
				SetCustom2(i, r.GetCustom2(i));
				SetCustom3(i, r.GetCustom3(i));
				SetCustom4(i, r.GetCustom4(i));
			}
		}
		RenderVertex(const RenderVertex& r, glm::mat4 model) : pos(TransformPoint(r.GetPosition(), model)), norm(TransformNormal(r.GetNormal(), model)), text(r.GetTextureCoordinate()), mat(r.GetMaterial()) {
			for (unsigned int i = 0; i < 5; i++) {
				SetCustom1(i, r.GetCustom1(i));
				SetCustom2(i, r.GetCustom2(i));
				SetCustom3(i, r.GetCustom3(i));
				SetCustom4(i, r.GetCustom4(i));
			}
		}
		glm::vec3 GetPosition() const { return pos; }
		glm::vec3 GetNormal() const { return norm; }
		glm::vec2 GetTextureCoordinate() const { return text; }
		Material GetMaterial() const { return mat; }

		glm::vec1 GetAttribute1(const ATTRIBUTE_TYPE type) const {
			if (IsMaterialAttribute(type)) {
				return GetMaterial().GetAttribute1(type);
			}
			if (IsCustomAttribute(type)) {
				return GetCustom1(CustomAttributeIndex(type));
			}
			return glm::vec1();
		}

		glm::vec2 GetAttribute2(const ATTRIBUTE_TYPE type) const {
			if (IsMaterialAttribute(type)) {
				return GetMaterial().GetAttribute2(type);
			}
			if (IsCustomAttribute(type)) {
				return GetCustom2(CustomAttributeIndex(type));
			}
			switch (type) {
				case ATTRIBUTE_TYPE::TEXTURE:
					return GetTextureCoordinate();
				default:
					return glm::vec2();
			}
		}

		glm::vec3 GetAttribute3(const ATTRIBUTE_TYPE type) const {
			if (IsMaterialAttribute(type)) {
				return GetMaterial().GetAttribute3(type);
			}
			if (IsCustomAttribute(type)) {
				return GetCustom3(CustomAttributeIndex(type));
			}
			switch (type) {
				case ATTRIBUTE_TYPE::POSITION:
					return GetPosition();
				case ATTRIBUTE_TYPE::NORMAL:
					return GetNormal();
				default:
					return glm::vec3();
			}
		}

		glm::vec4 GetAttribute4(const ATTRIBUTE_TYPE type) const {
			if (IsMaterialAttribute(type)) {
				return GetMaterial().GetAttribute4(type);
			}
			if (IsCustomAttribute(type)) {
				return GetCustom4(CustomAttributeIndex(type));
			}
			return glm::vec4();
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
}

#endif

