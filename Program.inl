namespace fagl {
	using std::string;

	bool ReadDataFromFile(const string& fileName, string& data)
	{
		std::fstream myfile;

		myfile.open(fileName.c_str(), std::ios::in);

		if (myfile.is_open())
		{
			string curLine;

			while (getline(myfile, curLine))
			{
				data += curLine;
				if (!myfile.eof())
				{
					data += "\n";
				}
			}

			myfile.close();
		}
		else
		{
			return false;
		}

		return true;
	}

	GLuint CreateShader(const string shaderName, CREATE_SHADER_TYPE shaderType)
	{
		string shaderSource;

		if (!ReadDataFromFile(shaderName, shaderSource))
		{
			std::cout << "Cannot find file name: " << shaderName << std::endl;
			exit(-1);
		}

		GLint length = shaderSource.length();
		const GLchar* shader = (const GLchar*)shaderSource.c_str();

		GLuint s = faglCreateShader(shaderType);
		glShaderSource(s, 1, &shader, &length);
		glCompileShader(s);

		char output[1024] = { 0 };
		glGetShaderInfoLog(s, 1024, &length, output);
		switch (shaderType) {
		case CREATE_SHADER_TYPE::VERTEX_SHADER:
			printf("VS compile log: %s\n", output);
			break;
		case CREATE_SHADER_TYPE::TESS_CONTROL_SHADER:
			printf("TCS compile log: %s\n", output);
			break;
		case CREATE_SHADER_TYPE::TESS_EVALUATION_SHADER:
			printf("TES compile log: %s\n", output);
			break;
		case CREATE_SHADER_TYPE::GEOMETRY_SHADER:
			printf("GS compile log: %s\n", output);
			break;
		case CREATE_SHADER_TYPE::FRAGMENT_SHADER:
			printf("FS compile log: %s\n", output);
			break;
		default:
			printf("Unknown compile log: %s\n", output);
			break;
		}
		return s;
	}

	GLuint CreateProgram(const string vs, const string tcs, const string tes, const string gs, const string fs)
	{
		GLuint gProgram = glCreateProgram();
		if (!vs.empty()) {
			GLuint v = CreateShader(vs, CREATE_SHADER_TYPE::VERTEX_SHADER);
			glAttachShader(gProgram, v);
		}
		if (!tcs.empty()) {
			GLuint tc = CreateShader(tcs, CREATE_SHADER_TYPE::TESS_CONTROL_SHADER);
			glAttachShader(gProgram, tc);
		}
		if (!tes.empty()) {
			GLuint te = CreateShader(tes, CREATE_SHADER_TYPE::TESS_EVALUATION_SHADER);
			glAttachShader(gProgram, te);
		}
		if (!gs.empty()) {
			GLuint g = CreateShader(gs, CREATE_SHADER_TYPE::GEOMETRY_SHADER);
			glAttachShader(gProgram, g);
		}
		if (!fs.empty()) {
			GLuint f = CreateShader(fs, CREATE_SHADER_TYPE::FRAGMENT_SHADER);
			glAttachShader(gProgram, f);
		}

		glLinkProgram(gProgram);

		GLint status;
		glGetProgramiv(gProgram, GL_LINK_STATUS, &status);

		if (status != GL_TRUE)
		{
			std::cout << "Program link failed" << std::endl;
			exit(-1);
		}

		return gProgram;
	}
}