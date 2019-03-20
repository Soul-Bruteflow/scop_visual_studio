#include "scop.h"

void		set_model(t_scop *scop)
{
	t_mat4	scale;
	t_mat4	translate;

	scop->scale = mat_scale(scop->scale_factor);
	scop->translate = mat_translate(scop->translate_factor);
	scop->translate_cent = mat_translate(scop->object_center);
	scop->translate_back = mat_translate(scop->object_back);
	scop->rotate = mat_rotate(scop->rotate_x, vec3_set(0.0f, 1.0f, 0.0f));
	//scop->model = mat_scale(scop->scale_factor);
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

t_mat4		mat_rotate(float angle, t_vec3 axis)
{
	float c;
	float s;

	c = cosf(angle * M_PI / 180.0f);
	s = sinf(angle * M_PI / 180.0f);
	return (mat_set_rotate(c, s, axis));
}

t_mat4		mat_set_rotate(float c, float s, t_vec3 a)
{
	t_mat4	res;

	res = mat_init(0);
	res.m[0][0] = a.x * a.x * (1.0f - c) + c;
	res.m[1][0] = a.y * a.x * (1.0f - c) + a.z * s;
	res.m[2][0] = a.z * a.x * (1.0f - c) - a.y * s;
	res.m[0][1] = a.x * a.y * (1.0f - c) - a.z * s;
	res.m[1][1] = a.y * a.y * (1.0f - c) + c;
	res.m[2][1] = a.z * a.y * (1.0f - c) + a.x * s;
	res.m[0][2] = a.x * a.z * (1.0f - c) + a.y * s;
	res.m[1][2] = a.y * a.z * (1.0f - c) - a.x * s;
	res.m[2][2] = a.z * a.z * (1.0f - c) + c;
	res.m[3][3] = 1.0f;
	return (res);
}
