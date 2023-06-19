#ifndef FAGL_MESH_H
#define FAGL_MESH_H

#include "RenderVertex.h"
#include "BasicTypes.h"
#include <map>

namespace fagl {
	struct TempTriangle {

		std::string material_name;
		glm::ivec3 vertex_ids;
		glm::ivec3 normal_ids;
		glm::ivec3 texture_ids;

		TempTriangle(std::string name = std::string(""), glm::ivec3 vertices = glm::ivec3(-1, -1, -1), glm::ivec3 normals = glm::ivec3(-1, -1, -1), glm::ivec3 textures = glm::ivec3(-1, -1, -1)) : material_name(name), vertex_ids(vertices), normal_ids(normals), texture_ids(textures) {};
	};

	class Mesh {
		protected:
			std::map<std::string, Material> material_ref;
			std::vector<glm::vec3> temp_vertices;
			std::vector<glm::vec3> temp_normals;
			std::vector<glm::vec2> temp_textures;
			std::vector<TempTriangle> temp_triangles;

			void CalculateRenderVertices();
			void CalculateMissingNormals();
			RenderVertex GenerateRenderVertex(const std::string material, const int vertex_index, const int normal_index, const int texture_index) const;

		public:
			std::vector<RenderVertex> render_vertices;

			Mesh(const std::string& filename, const glm::vec3 offset = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
			Mesh(const Mesh &mesh, const glm::vec3 offset = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
			Mesh();

			/// <summary>
			/// Generates VAO from the given list of attributes.
			/// </summary>
			/// <param name="attributes"> Types of the attributes.</param>
			/// <returns> Pointer to the VAO.</returns>
			FAGLvertexarrar GenerateVAO(std::vector<ATTRIBUTE_TYPE> attributes);

			/// <summary>
			/// Generates VAO from the given attribute.
			/// </summary>
			/// <param name="attrib1"> Type of the attribute.</param>
			/// <returns> Pointer to the VAO.</returns>
			FAGLvertexarrar GenerateVAO(ATTRIBUTE_TYPE attrib1);

			/// <summary>
			/// Generates VAO from the given attributes.
			/// </summary>
			/// <param name="attrib1"> Type of the first attribute.</param>
			/// <param name="attrib2"> Type of the second attribute.</param>
			/// <returns>  Pointer to the VAO.</returns>
			FAGLvertexarrar GenerateVAO(ATTRIBUTE_TYPE attrib1, ATTRIBUTE_TYPE attrib2);

			/// <summary>
			/// Generates VAO from the given attributes.
			/// </summary>
			/// <param name="attrib1"> Type of the first attribute.</param>
			/// <param name="attrib2"> Type of the second attribute.</param>
			/// <param name="attrib3"> Type of the third attribute.</param>
			/// <returns>  Pointer to the VAO.</returns>
			FAGLvertexarrar GenerateVAO(ATTRIBUTE_TYPE attrib1, ATTRIBUTE_TYPE attrib2, ATTRIBUTE_TYPE attrib3);
	};
}

#include "Mesh.inl"

#endif