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
uniform bool color_mode_2;
uniform bool color_mode_3;
uniform bool color_mode_4;
mat4 rotate;
mat4 mvp;

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

flat	out vec4 fragment_color_flat;
smooth	out vec4 fragment_color_smooth;

void main()
{
	rotate = trans_back * rotate_z * rotate_y * rotate_x * trans_cent;
	mvp = proj * view * translate * rotate * scale;
	gl_Position =  mvp * vec4(position.x, position.y, position.z, 1.0);

	fragment_color_flat = color;
	if (color_mode_2)
	{
		fragment_color_smooth = color;
	}
	if (color_mode_3)
	{
		fragment_color_smooth = vec4(position.y * 0.1f + 0.45f,
		position.z * 0.9 + position.y * 0.1f, position.x * 1.5f + position.y * 1.1f, 1.0f);
	}
	if (color_mode_4)
	{
		fragment_color_smooth = vec4(position * 0.4f + 0.4f, 1.0f);
	}

}
//VERTEX SHADER