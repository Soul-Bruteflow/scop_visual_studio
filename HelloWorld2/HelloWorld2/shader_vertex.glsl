#version 400 core

uniform mat4 view;
uniform mat4 proj;
uniform mat4 scale;
uniform mat4 translate;
uniform mat4 trans_cent;
uniform mat4 trans_back;
uniform mat4 rotate_x;
uniform mat4 rotate_y;
uniform mat4 rotate_z;
mat4 rotate;
mat4 mvp;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;
out vec4 fragmentColor;

void main()
{
	rotate = trans_back * rotate_z * rotate_y * rotate_x * trans_cent;
	mvp = proj * view * translate * rotate * scale;
	gl_Position =  mvp * vec4(aPos.x, aPos.y, aPos.z, 1.0);
	fragmentColor = color;
}
//VERTEX SHADER