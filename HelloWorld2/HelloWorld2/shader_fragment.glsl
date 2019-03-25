#version 400 core

out vec4 color;

flat	in vec4 fragment_color_flat;
smooth	in vec4 fragment_color_smooth;

in vec2 texture_uv;
uniform sampler2D tex;

uniform bool color_mode_1;
uniform bool color_mode_2_1;
uniform bool color_mode_3_1;
uniform bool color_mode_4_1;
uniform bool color_mode_5_1;
uniform bool color_mode_6_1;
uniform bool color_mode_7_1;

float grey;

void main()
{
	color = fragment_color_flat;
	grey = (0.2125 * color.x + 0.7154 * color.y + 0.0721 * color.z) / 3.0f;
	color = vec4(grey, grey, grey, 1.0f);
	if (color_mode_1)
	{
		color = fragment_color_flat;
	}
	if (color_mode_2_1 || color_mode_3_1 || color_mode_4_1)
	{
		color = fragment_color_smooth;
	}
	if (color_mode_5_1 || color_mode_6_1 || color_mode_7_1)
	{
		color = texture(tex, texture_uv);
	}
}
//FRAGMENT SHADER