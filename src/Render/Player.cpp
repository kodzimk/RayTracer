#include "Player.h"

Player::Player()
{
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

Player::~Player()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void Player::Draw(unsigned int program)
{
	glBindVertexArray(this->VAO);
	glUniformMatrix4fv(glGetUniformLocation(program, "playerMatrix"), 1, GL_FALSE, glm::value_ptr(playerMatrix));
	glDrawArrays(GL_TRIANGLES, 0, 12);
	glBindVertexArray(0);
}

void Player::Input(GLFWwindow* window)
{
	
	if (glfwGetKey(window, GLFW_KEY_W) > 0)
	{
		position.y += speed*0.001f;
		movement.y += speed * 0.001f;
		playerMatrix = glm::translate(playerMatrix, movement);
	}
	if (glfwGetKey(window, GLFW_KEY_S) > 0)
	{
		position.y -= speed * 0.001f;
		movement.y -= speed * 0.001f;
		playerMatrix = glm::translate(playerMatrix, movement);
	}
	if (glfwGetKey(window, GLFW_KEY_D) > 0)
	{
		position.x += speed * 0.001f;
		movement.x += speed * 0.001f;
		playerMatrix = glm::translate(playerMatrix, movement);
	}
	if (glfwGetKey(window, GLFW_KEY_A) > 0)
	{
		position.x -= speed * 0.001f;
		movement.x -= speed * 0.001f;
		playerMatrix = glm::translate(playerMatrix, movement);
	}

	movement = { 0.0f,0.0f,0.0f };
}
