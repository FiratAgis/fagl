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

	GLuint CreateShader(const string shaderName, GLenum shaderType)
	{
		string shaderSource;

		if (!ReadDataFromFile(shaderName, shaderSource))
		{
			std::cout << "Cannot find file name: " << shaderName << std::endl;
			exit(-1);
		}

		GLint length = shaderSource.length();
		const GLchar* shader = (const GLchar*)shaderSource.c_str();

		GLuint s = glCreateShader(shaderType);
		glShaderSource(s, 1, &shader, &length);
		glCompileShader(s);

		char output[1024] = { 0 };
		glGetShaderInfoLog(s, 1024, &length, output);
		switch (shaderType) {
		case GL_VERTEX_SHADER:
			printf("VS compile log: %s\n", output);
			break;
		case GL_TESS_CONTROL_SHADER:
			printf("TCS compile log: %s\n", output);
			break;
		case GL_TESS_EVALUATION_SHADER:
			printf("TES compile log: %s\n", output);
			break;
		case GL_GEOMETRY_SHADER:
			printf("GS compile log: %s\n", output);
			break;
		case GL_FRAGMENT_SHADER:
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
			GLuint v = CreateShader(vs, GL_VERTEX_SHADER);
			glAttachShader(gProgram, v);
		}
		if (!tcs.empty()) {
			GLuint tc = CreateShader(tcs, GL_TESS_CONTROL_SHADER);
			glAttachShader(gProgram, tc);
		}
		if (!tes.empty()) {
			GLuint te = CreateShader(tes, GL_TESS_EVALUATION_SHADER);
			glAttachShader(gProgram, te);
		}
		if (!gs.empty()) {
			GLuint g = CreateShader(gs, GL_GEOMETRY_SHADER);
			glAttachShader(gProgram, g);
		}
		if (!fs.empty()) {
			GLuint f = CreateShader(fs, GL_FRAGMENT_SHADER);
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