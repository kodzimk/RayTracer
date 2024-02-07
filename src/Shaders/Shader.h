#include"..\external\config.h"

class Shader
{
public:
	Shader(const char* vertex, const char* fragment);
	~Shader();

	void use();

public:
	unsigned int program;
};

