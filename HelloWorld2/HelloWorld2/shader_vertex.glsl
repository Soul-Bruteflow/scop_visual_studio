#version 400 core

uniform mat4 view;
uniform mat4 proj;
uniform mat4 model;

layout (location = 0) in vec3 aPos;

void main()
{
   gl_Position = proj * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
//VERTEX SHADER