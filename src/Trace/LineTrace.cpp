#include "LineTrace.h"

bool isCollide(glm::vec3 position,glm::vec3 playerPosition,glm::vec3 scale)
{

		glm::vec3 box1right = { position.x,position.y,position.z };
		glm::vec3 box1Left = { position.x + 0.2f,position.y + 0.2f,position.z };

		glm::vec3 box2right = { playerPosition.x,playerPosition.y,playerPosition.z };
		glm::vec3 box2Left = { scale.x + playerPosition.x ,scale.y + playerPosition.y ,playerPosition.z };

		if (box2right.x <= box1Left.x &&
			box2Left.x >= box1right.x &&
			box2right.y <= box1Left.y &&
			box2Left.y >= box1right.y)
		{
			return true;
		}
	
	return false;
}

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

void LineTrace::update(glm::vec3 position,glm::vec3& rotation)
{
	this->position = glm::vec3(position.x+0.1f, position.y+0.1f, position.z);
	
	matrix = glm::mat4(1.0f);
	matrix = glm::translate(matrix, position);
	matrix = glm::rotate(matrix, rotation.x, glm::vec3(0.0f, 0.0f, 1.0f));

	this->angles.x = rotation.x;
}

bool LineTrace::isLineTrace(glm::vec3 position)
{
	glm::vec3 actualPosition = {this->position.x/this->scale.x,this->position.y / this->scale.y,this->position.z};

	for (int i = 0; i < 1000; i++)
	{
		float x = cos(this->angles.x);
		float y = sin(this->angles.x);

		actualPosition.x += x;
		actualPosition.y += y;

		if (isCollide(position, actualPosition, this->scale))
		{
			std::cout << "niger";
			return true;
		}
	}

	return false;
}

void LineTrace::Draw(unsigned int program)
{
	glBindVertexArray(this->VAO);
	glUniformMatrix4fv(glGetUniformLocation(program, "playerMatrix"), 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_TRIANGLES, 0, 12);
	glBindVertexArray(0);
}
