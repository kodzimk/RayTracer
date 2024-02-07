#include"..\external\config.h"

class Player
{
public:
	Player();
	~Player();


	void Draw(unsigned int program);
	void Input(GLFWwindow* window);

public:
	glm::vec3 position = { 0.0f,0.0f,0.0f };
	glm::mat4 playerMatrix = glm::mat4(1.0f);
	glm::vec3 movement = glm::vec3(0.0f);
	float rayTraceDistance;
	float speed = 0.02f;
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

