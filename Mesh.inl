#include <sstream>

namespace fagl {
	using std::vector;
	using std::string;
	using std::cout;
	using std::endl;

	using glm::vec3;
	using glm::vec2;
	using glm::ivec3;

	using glm::mat4;

	void GetVertData(string data, int* vLoc, int* tLoc, int* nLoc)
	{
		vector<int> elements = TokenizeAsInteger(data, "/");

		if (elements.size() == 1) {
			*(vLoc) = elements[0];
			*(tLoc) = 0;
			*(nLoc) = 0;
		}
		else if (elements.size() == 2) {
			*(vLoc) = elements[0];
			*(tLoc) = elements[1];
			*(nLoc) = 0;
		}
		else if (elements.size() == 3) {
			*(vLoc) = elements[0];
			*(tLoc) = elements[1];
			*(nLoc) = elements[2];
		}
	}


	RenderVertex Mesh::GenerateRenderVertex(const string material, const int vertex_index, const int normal_index, const int texture_index) const {
		vec3 pos = vertex_index >= 0 ? temp_vertices[vertex_index] : vec3(0, 0, 0);
		vec3 norm = normal_index >= 0 ? temp_normals[normal_index] : vec3(0, 0, 0);
		vec2 tex = texture_index >= 0 ? temp_textures[texture_index] : vec2(0, 0);
		Material mat = ((material_ref.count(material) > 0) ? (material_ref.at(material)) : Material());
		return RenderVertex(pos, norm, tex, mat);
	}

	void Mesh::CalculateRenderVertices()
	{
		cout << "Calculating Render Vertices" << endl;
		for (TempTriangle tri : temp_triangles) {
			render_vertices.push_back(GenerateRenderVertex(tri.material_name, tri.vertex_ids.x, tri.normal_ids.x, tri.texture_ids.x));
			render_vertices.push_back(GenerateRenderVertex(tri.material_name, tri.vertex_ids.y, tri.normal_ids.y, tri.texture_ids.y));
			render_vertices.push_back(GenerateRenderVertex(tri.material_name, tri.vertex_ids.z, tri.normal_ids.z, tri.texture_ids.z));
		}
	}

	void Mesh::CalculateMissingNormals() {
		cout << "Calculating normals" << endl;
		for (TempTriangle tri : temp_triangles) {
			if (IsComplete(tri.vertex_ids) && !IsComplete(tri.normal_ids)) {
				vec3 normal = GetSurfaceNormal(temp_vertices[tri.vertex_ids.x], temp_vertices[tri.vertex_ids.y], temp_vertices[tri.vertex_ids.z]);
				temp_normals.push_back(normal);
				if (tri.normal_ids.x < 0)
					tri.normal_ids.x = temp_normals.size() - 1;

				if (tri.normal_ids.y < 0)
					tri.normal_ids.y = temp_normals.size() - 1;

				if (tri.normal_ids.z < 0)
					tri.normal_ids.z = temp_normals.size() - 1;

			}
		}
	}

	Mesh::Mesh(const string& filename, const vec3 offset, const vec3 rotation, const vec3 scale)
	{

		cout << "Starting reading mesh: " << filename << endl;

		std::fstream myFile;

		mat4 mat = glm::translate(mat4(1.0f), offset) * RotationMatrix(rotation) * glm::scale(mat4(1.0f), scale);

		myFile.open(filename.c_str(), std::ios::in);
		if (myFile.is_open()) {
			string currentLine;
			string curMat("");
			while (getline(myFile, currentLine)) {
				std::stringstream str(currentLine);
				GLfloat c1, c2, c3;
				string tmp;
				if (currentLine.length() >= 2)
				{
					if (CompareWithoutCase(currentLine[0], 'v'))
					{
						if (CompareWithoutCase(currentLine[1], 't'))
						{
							str >> tmp;
							str >> c1 >> c2;
							temp_textures.push_back(vec2(c1, c2));
						}
						else if (CompareWithoutCase(currentLine[1], 'n'))
						{
							str >> tmp;
							str >> c1 >> c2 >> c3;
							temp_normals.push_back(TransformNormal(vec3(c1, c2, c3), mat));
						}
						else if (CompareWithoutCase(currentLine[1], ' '))
						{
							str >> tmp;
							str >> c1 >> c2 >> c3;
							temp_vertices.push_back(TransformPoint(vec3(c1, c2, c3), mat));
						}
					}
					else if (CompareWithoutCase(currentLine[0], 'f'))
					{
						str >> tmp;
						int vIndex[3], nIndex[3], tIndex[3];

						string vert1;
						string vert2;
						string vert3;

						str >> vert1;
						GetVertData(vert1, vIndex, tIndex, nIndex);

						str >> vert2;

						GetVertData(vert2, vIndex + 1, tIndex + 1, nIndex + 1);

						str >> vert3;

						GetVertData(vert3, vIndex + 2, tIndex + 2, nIndex + 2);

						temp_triangles.push_back(TempTriangle(curMat, ivec3(vIndex[0] - 1, vIndex[1] - 1, vIndex[2] - 1), ivec3(nIndex[0] - 1, nIndex[1] - 1, nIndex[2] - 1), ivec3(tIndex[0] - 1, tIndex[1] - 1, tIndex[2] - 1)));
					}
					else if (CompareWithoutCase(currentLine, "mtllib")) {
						str >> tmp;
						str >> tmp;
						vector<Material> materials = ReadMaterialFile(tmp);
						for (unsigned int i = 0; i < materials.size(); i++) {
							material_ref[materials[i].GetName()] = materials[i];
						}
					}
					else if (CompareWithoutCase(currentLine, "usemtl")) {
						str >> tmp;
						curMat.clear();
						str >> curMat;
					}
				}

			}
		}
		myFile.close();
		cout << "Finished reading mesh: " << filename << endl;

		CalculateMissingNormals();
		CalculateRenderVertices();
		temp_vertices.clear();
		temp_normals.clear();
		temp_textures.clear();
		temp_triangles.clear();

		cout << "Finished mesh creation: " << filename << endl;
	}

	Mesh::Mesh(const Mesh& mesh, const glm::vec3 offset, const glm::vec3 rotation, const glm::vec3 scale)
	{
		mat4 mat = glm::translate(mat4(1.0f), offset) * RotationMatrix(rotation) * glm::scale(mat4(1.0f), scale);
		for (RenderVertex vert : mesh.render_vertices) {
			RenderVertex temp = RenderVertex(vert, mat);
			render_vertices.push_back(temp);
		}
	}

	Mesh::Mesh()
	{
	}

	GLuint Mesh::GenerateVAO(vector<ATTRIBUTE_TYPE> attributes)
	{
		cout << "Starting VAO creation" << endl;

		const unsigned int attributeElementCount = AttributeElementCount(attributes);
		const unsigned int amount = render_vertices.size();

		GLfloat* vertex_data = new GLfloat[attributeElementCount * amount];


		cout << "Processing render vertices" << endl;

		for (unsigned int i = 0; i < render_vertices.size(); i++) {
			unsigned int count = 0;
			unsigned int index = 0;

			RenderVertex render_vert = render_vertices[i];
			while (count < attributeElementCount && index < attributes.size()) {

				ATTRIBUTE_TYPE type = attributes[index];
				unsigned int size = AttributeElementCount(type);
				glm::vec4 temp = render_vert.GetAttribute(type);

				switch (size) {
				case 4:
					vertex_data[i * attributeElementCount + count + 3] = temp.w;
				case 3:
					vertex_data[i * attributeElementCount + count + 2] = temp.z;
				case 2:
					vertex_data[i * attributeElementCount + count + 1] = temp.y;
				case 1:
					vertex_data[i * attributeElementCount + count] = temp.x;
				case 0:
					break;
				}

				count += size;
				index++;
			}
		}
		cout << "Finished processing render vertices" << endl;
		cout << "Creating arrays" << endl;
		GLuint VAO;
		GLuint VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, attributeElementCount * amount * sizeof(GLfloat), vertex_data, GL_STATIC_DRAW);

		cout << "Setting attributes" << endl;

		unsigned int count = 0;
		for (unsigned int i = 0; i < attributes.size(); i++) {
			unsigned int size = AttributeElementCount(attributes[i]);
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, size, GL_FLOAT, GL_FALSE, attributeElementCount * sizeof(float), (void*)(count * sizeof(float)));
			count += size;
		}

		cout << "Finished VAO creation" << endl;

		glBindVertexArray(0);
		delete[] vertex_data;
		return VAO;
	}
	GLuint Mesh::GenerateVAO(ATTRIBUTE_TYPE attrib1)
	{
		cout << "Starting VAO creation" << endl;

		const unsigned int attributeElementCount = AttributeElementCount(attrib1);
		const unsigned int amount = render_vertices.size();

		GLfloat* vertex_data = new GLfloat[attributeElementCount * amount];


		cout << "Processing render vertices" << endl;

		for (unsigned int i = 0; i < render_vertices.size(); i++) {

			RenderVertex render_vert = render_vertices[i];

			glm::vec4 temp = render_vert.GetAttribute(attrib1);

			switch (attributeElementCount) {
			case 4:
				vertex_data[i * attributeElementCount + 3] = temp.w;
			case 3:
				vertex_data[i * attributeElementCount + 2] = temp.z;
			case 2:
				vertex_data[i * attributeElementCount + 1] = temp.y;
			case 1:
				vertex_data[i * attributeElementCount] = temp.x;
			case 0:
				break;
			}
		}
		cout << "Finished processing render vertices" << endl;
		cout << "Creating arrays" << endl;
		GLuint VAO;
		GLuint VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, attributeElementCount * amount * sizeof(GLfloat), vertex_data, GL_STATIC_DRAW);

		cout << "Setting attributes" << endl;

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, attributeElementCount, GL_FLOAT, GL_FALSE, attributeElementCount * sizeof(float), (void*)(0 * sizeof(float)));

		cout << "Finished VAO creation" << endl;

		glBindVertexArray(0);
		delete[] vertex_data;
		return VAO;
	}
	GLuint Mesh::GenerateVAO(ATTRIBUTE_TYPE attrib1, ATTRIBUTE_TYPE attrib2)
	{
		cout << "Starting VAO creation" << endl;

		const unsigned int size1 = AttributeElementCount(attrib1);
		const unsigned int size2 = AttributeElementCount(attrib2);
		const unsigned int attributeElementCount = size1 + size2;
		const unsigned int amount = render_vertices.size();

		GLfloat* vertex_data = new GLfloat[attributeElementCount * amount];


		cout << "Processing render vertices" << endl;

		for (unsigned int i = 0; i < render_vertices.size(); i++) {

			RenderVertex render_vert = render_vertices[i];

			glm::vec4 temp = render_vert.GetAttribute(attrib1);

			switch (size1) {
			case 4:
				vertex_data[i * attributeElementCount + 3] = temp.w;
			case 3:
				vertex_data[i * attributeElementCount + 2] = temp.z;
			case 2:
				vertex_data[i * attributeElementCount + 1] = temp.y;
			case 1:
				vertex_data[i * attributeElementCount] = temp.x;
			case 0:
				break;
			}


			temp = render_vert.GetAttribute(attrib2);

			switch (size2) {
			case 4:
				vertex_data[i * attributeElementCount + size1 + 3] = temp.w;
			case 3:
				vertex_data[i * attributeElementCount + size1 + 2] = temp.z;
			case 2:
				vertex_data[i * attributeElementCount + size1 + 1] = temp.y;
			case 1:
				vertex_data[i * attributeElementCount + size1] = temp.x;
			case 0:
				break;
			}
		}
		cout << "Finished processing render vertices" << endl;
		cout << "Creating arrays" << endl;
		GLuint VAO;
		GLuint VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, attributeElementCount * amount * sizeof(GLfloat), vertex_data, GL_STATIC_DRAW);

		cout << "Setting attributes" << endl;

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, size1, GL_FLOAT, GL_FALSE, attributeElementCount * sizeof(float), (void*)(0 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, size2, GL_FLOAT, GL_FALSE, attributeElementCount * sizeof(float), (void*)(size1 * sizeof(float)));

		cout << "Finished VAO creation" << endl;

		glBindVertexArray(0);
		delete[] vertex_data;
		return VAO;
	}
	GLuint Mesh::GenerateVAO(ATTRIBUTE_TYPE attrib1, ATTRIBUTE_TYPE attrib2, ATTRIBUTE_TYPE attrib3)
	{
		cout << "Starting VAO creation" << endl;

		const unsigned int size1 = AttributeElementCount(attrib1);
		const unsigned int size2 = AttributeElementCount(attrib2);
		const unsigned int size3 = AttributeElementCount(attrib3);
		const unsigned int attributeElementCount = size1 + size2 + size3;
		const unsigned int amount = render_vertices.size();

		GLfloat* vertex_data = new GLfloat[attributeElementCount * amount];


		cout << "Processing render vertices" << endl;

		for (unsigned int i = 0; i < render_vertices.size(); i++) {

			RenderVertex render_vert = render_vertices[i];

			glm::vec4 temp = render_vert.GetAttribute(attrib1);

			switch (size1) {
			case 4:
				vertex_data[i * attributeElementCount + 3] = temp.w;
			case 3:
				vertex_data[i * attributeElementCount + 2] = temp.z;
			case 2:
				vertex_data[i * attributeElementCount + 1] = temp.y;
			case 1:
				vertex_data[i * attributeElementCount] = temp.x;
			case 0:
				break;
			}


			temp = render_vert.GetAttribute(attrib2);

			switch (size2) {
			case 4:
				vertex_data[i * attributeElementCount + size1 + 3] = temp.w;
			case 3:
				vertex_data[i * attributeElementCount + size1 + 2] = temp.z;
			case 2:
				vertex_data[i * attributeElementCount + size1 + 1] = temp.y;
			case 1:
				vertex_data[i * attributeElementCount + size1] = temp.x;
			case 0:
				break;
			}

			temp = render_vert.GetAttribute(attrib3);

			switch (size3) {
			case 4:
				vertex_data[i * attributeElementCount + size1 + size2 + 3] = temp.w;
			case 3:
				vertex_data[i * attributeElementCount + size1 + size2 + 2] = temp.z;
			case 2:
				vertex_data[i * attributeElementCount + size1 + size2 + 1] = temp.y;
			case 1:
				vertex_data[i * attributeElementCount + size1 + size2] = temp.x;
			case 0:
				break;
			}
		}
		cout << "Finished processing render vertices" << endl;
		cout << "Creating arrays" << endl;
		GLuint VAO;
		GLuint VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, attributeElementCount * amount * sizeof(GLfloat), vertex_data, GL_STATIC_DRAW);

		cout << "Setting attributes" << endl;

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, size1, GL_FLOAT, GL_FALSE, attributeElementCount * sizeof(float), (void*)(0 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, size2, GL_FLOAT, GL_FALSE, attributeElementCount * sizeof(float), (void*)(size1 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, size3, GL_FLOAT, GL_FALSE, attributeElementCount * sizeof(float), (void*)((size1 + size2) * sizeof(float)));

		cout << "Finished VAO creation" << endl;

		glBindVertexArray(0);
		delete[] vertex_data;
		return VAO;
	}
}
