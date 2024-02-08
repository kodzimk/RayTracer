#include"..\external\config.h"

class LineTrace
{
public:
	LineTrace(float length, glm::vec3 position);
	LineTrace();
	~LineTrace();

	void Draw(unsigned int program);
	void update(glm::vec3 position, glm::vec3& moveement);

public:

	unsigned int VAO, VBO;
	float length;
	glm::vec3 position;
	glm::mat4 matrix;
	glm::vec3 angles;
	glm::vec3 scale;


};


