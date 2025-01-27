namespace fagl {
	using std::string;

	inline bool ReadDataFromFile(const string& fileName, string& data)
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

	inline FAGLshader CreateShader(const string shaderName, CREATE_SHADER_TYPE shaderType)
	{
		string shaderSource;

		if (!ReadDataFromFile(shaderName, shaderSource))
		{
			std::cout << "Cannot find file name: " << shaderName << std::endl;
			exit(-1);
		}

		GLint length = shaderSource.length();
		const GLchar* shader = (const GLchar*)shaderSource.c_str();

		FAGLshader s = faglCreateShader(shaderType);
		faglShaderSource(s, 1, &shader, &length);
		faglCompileShader(s);

		char output[1024] = { 0 };
		faglGetShaderInfoLog(s, 1024, &length, output);
#ifdef _FAGL_PROGRESS_VERBOSE
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
#endif
		return s;
	}

	inline FAGLprogram CreateProgram(const string vs, const string tcs, const string tes, const string gs, const string fs)
	{
		FAGLprogram gProgram = faglCreateProgram();
		if (!vs.empty()) {
			FAGLshader v = CreateShader(vs, CREATE_SHADER_TYPE::VERTEX_SHADER);
			faglAttachShader(gProgram, v);
		}
		if (!tcs.empty()) {
			FAGLshader tc = CreateShader(tcs, CREATE_SHADER_TYPE::TESS_CONTROL_SHADER);
			faglAttachShader(gProgram, tc);
		}
		if (!tes.empty()) {
			FAGLshader te = CreateShader(tes, CREATE_SHADER_TYPE::TESS_EVALUATION_SHADER);
			faglAttachShader(gProgram, te);
		}
		if (!gs.empty()) {
			FAGLshader g = CreateShader(gs, CREATE_SHADER_TYPE::GEOMETRY_SHADER);
			faglAttachShader(gProgram, g);
		}
		if (!fs.empty()) {
			FAGLshader f = CreateShader(fs, CREATE_SHADER_TYPE::FRAGMENT_SHADER);
			faglAttachShader(gProgram, f);
		}

		faglLinkProgram(gProgram);

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
