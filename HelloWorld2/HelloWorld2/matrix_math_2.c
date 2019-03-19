#include "scop.h"

t_mat4		mat_scale(float f)
{
	t_mat4	result;

	result.m[0][0] *= f;
	result.m[1][1] *= f;
	result.m[2][2] *= f;
	return (result);
}

t_mat4		mat_translate(t_vec3 v)
{
	t_mat4	result;

	result.m[0][3] = v.x;
	result.m[1][3] = v.y;
	result.m[2][3] = v.z;
	return (result);
}
