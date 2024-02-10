#include "LineTrace.h"

LineTrace::LineTrace(float length,glm::vec3 position)
{
	scale = glm::vec3(1.0f);


	float plane[12] = {
		// Coords    
		 0.1f * length * 0.01f , -0.1f * length * 0.01f,
		-0.1f * length * 0.01f, -0.1f * length * 0.01f ,
		-0.1f * length * 0.01f,  0.1f * length * 0.01f,

		 0.1f * length  ,0.1f * length,
		 0.1f * length * 0.01f, -0.1f * length * 0.01f,
		-0.1f * length * 0.01f,  0.1f * length * 0.01f
	};

	scale.x = 0.2f*length;
	scale.y = 0.2f*length;

	matrix = glm::mat4(1.0f);
	matrix = glm::translate(matrix, glm::vec3(position.x + 0.2f/scale.x, position.y + 0.2f/scale.y, position.z));
	this->position = glm::vec3(position.x + 0.2f / scale.x, position.y + 0.2f / scale.y, position.z);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(plane), plane, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

LineTrace::LineTrace()
{

}

LineTrace::~LineTrace()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void LineTrace::update(glm::vec3 position, glm::vec3& movement,glm::vec3& rotation)
{
	this->position = glm::vec3(this->position.x + movement.x, this->position.y + movement.y, position.z);

	if (rotation.x != 0.0f || rotation.y != 0.0f)
	{

	}

	matrix = glm::mat4(1.0f);
	matrix = glm::translate(matrix, position);
	matrix = glm::rotate(matrix, rotation.x, glm::vec3(0.0f, 0.0f, 1.0f));

	movement = glm::vec3(0.0f);
}

void LineTrace::Draw(unsigned int program)
{
	glBindVertexArray(this->VAO);
	glUniformMatrix4fv(glGetUniformLocation(program, "playerMatrix"), 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_TRIANGLES, 0, 12);
	glBindVertexArray(0);
}
