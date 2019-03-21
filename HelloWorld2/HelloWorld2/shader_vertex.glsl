#version 400 core

uniform mat4 view;
uniform mat4 proj;
uniform mat4 scale;
uniform mat4 translate;
uniform mat4 translate_cent;
uniform mat4 translate_back;
uniform mat4 rotate_x;
uniform mat4 rotate_y;
uniform mat4 rotate_z;
mat4 rotate;
mat4 mvp;

layout (location = 0) in vec3 aPos;

void main()
{
	rotate = translate_back * rotate_z * rotate_y * rotate_x * translate_cent;
	mvp = proj * view * translate * rotate * scale;
	gl_Position =  mvp * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
//VERTEX SHADER