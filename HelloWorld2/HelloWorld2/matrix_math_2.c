#include "scop.h"

void		set_model(t_scop *scop)
{
	t_mat4	scale;
	t_mat4	translate;

	scop->scale = mat_scale(scop->scale_factor);
	scop->translate = mat_translate(scop->translate_factor);
	scop->model = mat_scale(scop->scale_factor);
}

t_mat4		mat_scale(float scale_factor)
{
	t_mat4	result;

	result = mat_set_identity();
	result.m[0][0] *= scale_factor;
	result.m[1][1] *= scale_factor;
	result.m[2][2] *= scale_factor;
	return (result);
}

t_mat4		mat_translate(t_vec3 v)
{
	t_mat4	result;

	result = mat_set_identity();
	result.m[3][0] = v.x;
	result.m[3][1] = v.y;
	result.m[3][2] = v.z;
	return (result);
}
