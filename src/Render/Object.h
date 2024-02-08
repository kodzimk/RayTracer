#include"..\external\config.h"

class Object
{
public:
	Object(glm::vec3 position);
	~Object();

	void Draw(unsigned int program);

public:
	glm::vec3 position = { 0.0f,0.0f,0.0f };
	glm::mat4 objectMatrix = glm::mat4(1.0f);
	unsigned int  VBO, VAO;

	float plane[12] = {
		// Coords    
		 0.1f, -0.1f,
		-0.1f, -0.1f,
		-0.1f,  0.1f,

		 0.1f,  0.1f,
		 0.1f, -0.1f,
		-0.1f,  0.1f
	};


};

