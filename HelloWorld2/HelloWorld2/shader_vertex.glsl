#version 400 core

uniform mat4 camera;

layout (location = 0) in vec3 aPos;

void main()
{
   gl_Position = camera * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
//VERTEX SHADER