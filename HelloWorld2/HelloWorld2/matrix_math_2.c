/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:49 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:50:49 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		set_model_mats(t_scop *s)
{
	t_mat4	scale;
	t_mat4	translate;

	s->scale = mat_scale(s->scale_factor);
	s->translate = mat_translate(s->move_fac);
	s->trans_cent = mat_translate(s->object_center);
	s->trans_back = mat_translate(s->object_back);
	if (s->enable_rotate == 1)
		s->rotate_x = mat_rotate(s->rot_a_fac, vec3_set(0.0f, 1.0f, 0.0f));
	else if (s->enable_rotate == -1)
	{
		if (s->copy_auto == 1)
		{
			s->rot_x_fac = s->rot_a_fac;
			s->copy_auto = -1;
		}
		s->rotate_x = mat_rotate(s->rot_x_fac, vec3_set(0.0f, 1.0f, 0.0f));
	}
	s->rotate_y = mat_rotate(s->rot_y_fac, vec3_set(1.0f, 0.0f, 0.0f));
	s->rotate_z = mat_rotate(s->rot_z_fac, vec3_set(0.0f, 0.0f, 1.0f));
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
	float	c;
	float	s;

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