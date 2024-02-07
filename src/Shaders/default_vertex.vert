#vertex
#version 330 core

layout(location = 0) in vec3 aPos;

uniform mat4 playerMatrix;

void main()
{
  gl_Position = playerMatrix*vec4(aPos,1.0f);
}