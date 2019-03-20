#version 400 core

uniform mat4 view;
uniform mat4 proj;
uniform mat4 scale;
uniform mat4 translate;
uniform mat4 translate_cent;
uniform mat4 translate_back;
uniform mat4 rotate;

layout (location = 0) in vec3 aPos;

void main()
{
	gl_Position = proj * view * translate * translate_cent * rotate * translate_back * scale * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
//VERTEX SHADER