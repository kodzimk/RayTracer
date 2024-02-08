#include "Object.h"

Object::Object(glm::vec3 position)
{
	this->position = position;
	objectMatrix = glm::translate(objectMatrix, this->position);

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

Object::~Object()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}


void Object::Draw(unsigned int program)
{
	glBindVertexArray(this->VAO);
	glUniformMatrix4fv(glGetUniformLocation(program, "playerMatrix"), 1, GL_FALSE, glm::value_ptr(objectMatrix));

	glDrawArrays(GL_TRIANGLES, 0, 12);
	glBindVertexArray(0);
}
