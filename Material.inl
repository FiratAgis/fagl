#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "BasicTypes.h"

namespace fagl {
	using std::string;
	using std::vector;

	using glm::vec3;
	using glm::vec4;
	using glm::vec2;
	using glm::vec1;

	Material::Material(const string& materialFileContent) : ka(0, 0, 0), kd(0, 0, 0), ks(0, 0, 0), ns(0.0f), tr(0.0f), tf(0, 0, 0), ni(0.0f), illum(0), name("") {
		string currentLine;
		std::stringstream stream(materialFileContent);
		string tmp;
		while (getline(stream, currentLine)) {
			std::stringstream str(currentLine);
			GLfloat f1, f2, f3;
			if (currentLine.length() >= 2) {
				if (CompareWithoutCase(currentLine[0], 'k')) {
					if (CompareWithoutCase(currentLine[1], 'a')) {
						str >> tmp;
						str >> f1 >> f2 >> f3;
						ka = vec3(f1, f2, f3);
					}
					else if (CompareWithoutCase(currentLine[1], 'd')) {
						str >> tmp;
						str >> f1 >> f2 >> f3;
						kd = vec3(f1, f2, f3);
					}
					else if (CompareWithoutCase(currentLine[1], 's')) {
						str >> tmp;
						str >> f1 >> f2 >> f3;
						ks = vec3(f1, f2, f3);
					}
				}
				else if (CompareWithoutCase(currentLine[0], 'n')) {
					if (CompareWithoutCase(currentLine[1], 's')) {
						str >> tmp;
						str >> ns;
					}
					else if (CompareWithoutCase(currentLine[1], 'i')) {
						str >> tmp;
						str >> ni;
					}
					else if (CompareWithoutCase(currentLine, "newmtl")) {
						str >> tmp;
						str >> name;
					}
				}
				else if (CompareWithoutCase(currentLine[0], 't')) {
					if (CompareWithoutCase(currentLine[1], 'r')) {
						str >> tmp;
						str >> tr;
					}
					else if (CompareWithoutCase(currentLine[1], 'f')) {
						str >> tmp;
						str >> f1 >> f2 >> f3;
						tf = vec3(f1, f2, f3);
					}
				}
				else if (CompareWithoutCase(currentLine, "illum")) {
					str >> tmp;
					str >> illum;
				}
			}
		}

	}

	Material::Material(const Material& m) {
		name = m.GetName();
		ka = m.GetAmbient();
		kd = m.GetDiffuse();
		glm::vec4 specular = m.GetSpecular();
		ks = vec3(specular.x, specular.y, specular.z);
		ns = specular.w;
		glm::vec4 trans = m.GetTransperancy();
		tf = vec3(trans.x, trans.y, trans.z);
		tr = trans.w;
		ni = m.GetDensity();
		illum = m.GetIlluminationModel();

		for (unsigned int i = 0; i < 5; i++) {
			SetCustom1(i, m.GetCustom1(i));
			SetCustom2(i, m.GetCustom2(i));
			SetCustom3(i, m.GetCustom3(i));
			SetCustom4(i, m.GetCustom4(i));
		}
	}

	Material::Material(const string& material_name, const vec3 material_ka, const vec3 material_kd, const vec3 material_ks, const float material_ns, const float material_tr, const vec3 material_tf, const float material_ni, const int material_illum) : name(material_name), ka(material_ka), kd(material_kd), ks(material_ks), ns(material_ns), tr(material_tr), tf(material_tf), ni(material_ni), illum(material_illum) {}

	Material::Material() : ka(0, 0, 0), kd(0, 0, 0), ks(0, 0, 0), ns(0.0f), tr(0.0f), tf(0, 0, 0), ni(0.0f), illum(0), name("") { }

	string Material::GetName() const { return name; }
	vec3 Material::GetAmbient() const { return ka; }
	vec3 Material::GetDiffuse() const { return kd; }
	vec4 Material::GetSpecular() const { return vec4(ks.x, ks.y, ks.z, ns); }
	vec4 Material::GetTransperancy() const { return vec4(tf.x, tf.y, tf.z, tr); }
	float Material::GetDensity() const { return ni; }
	int Material::GetIlluminationModel() const { return illum; }

	vec1 Material::GetAttribute1(const ATTRIBUTE_TYPE type) const {
		if (IsCustomAttribute(type)) {
			return GetCustom1(CustomAttributeIndex(type));
		}
		switch (type) {
		case ATTRIBUTE_TYPE::DENSITY:
			return vec1(GetDensity());
		case ATTRIBUTE_TYPE::ILLUMINATION_MODEL:
			return vec1(GetIlluminationModel());
		default:
			return vec1();
		}
	}

	vec2 Material::GetAttribute2(const ATTRIBUTE_TYPE type) const {
		if (IsCustomAttribute(type)) {
			return GetCustom2(CustomAttributeIndex(type));
		}
		return vec2();
	}

	vec3 Material::GetAttribute3(const ATTRIBUTE_TYPE type) const {
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
			return vec3();
		}
	}

	vec4 Material::GetAttribute4(const ATTRIBUTE_TYPE type) const {
		if (IsCustomAttribute(type)) {
			return GetCustom4(CustomAttributeIndex(type));
		}
		switch (type) {
		case ATTRIBUTE_TYPE::SPECULAR_COLOR:
			return GetSpecular();
		case ATTRIBUTE_TYPE::TRANSPERANCY:
			return GetTransperancy();
		default:
			return vec4();
		}
	}

	vec4 Material::GetAttribute(const ATTRIBUTE_TYPE type) const {
		unsigned int size = AttributeElementCount(type);
		switch (size) {
		case 4:
			return vec4(GetAttribute4(type));
		case 3:
			return vec4(GetAttribute3(type), 0);
		case 2:
			return vec4(GetAttribute2(type), 0, 0);
		case 1:
			return vec4(GetAttribute1(type), 0, 0, 0);
		default:
			return vec4();
		}
	}

	vector<string> SplitPrograms(const string& program) {
		vector<std::string> retval;
		string del("newmtl");
		int start, end = -1 * del.size();
		do {
			start = end + del.size();
			end = program.find(del, start);
			retval.push_back("newmtl" + program.substr(start, end - start));
		} while (end != -1);
		return retval;
	}

	vector<Material> ReadMaterialFile(const string& filename) {
		vector<Material> retval;
		std::ifstream myFile(filename);
		string str;
		if (myFile) {
			std::ostringstream ss;
			ss << myFile.rdbuf(); // reading data
			str = ss.str();
		}
		vector<string> programs = SplitPrograms(str);

		for (unsigned int i = 0; i < programs.size(); i++) {
			retval.push_back(Material(programs[i]));
		}
		return retval;
	}
}

