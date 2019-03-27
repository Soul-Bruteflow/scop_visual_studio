/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:46 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:50:46 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat4		mat_build_view(t_vec3 eye, t_vec3 center, t_vec3 up)
{
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;

	z = vec3_normalize(vec3_sub(eye, center));
	y = vec3_normalize(up);
	x = vec3_normalize(vec3_cross(y, z));
	y = vec3_normalize(vec3_cross(z, x));
	return (set_view_help(x, y, z, eye));
}

t_mat4		set_view_help(t_vec3 x, t_vec3 y, t_vec3 z, t_vec3 eye)
{
	t_mat4	result;

	result.m[0][0] = x.x;
	result.m[1][0] = x.y;
	result.m[2][0] = x.z;
	result.m[3][0] = -(vec3_dot(x, eye));
	result.m[0][1] = y.x;
	result.m[1][1] = y.y;
	result.m[2][1] = y.z;
	result.m[3][1] = -(vec3_dot(y, eye));
	result.m[0][2] = z.x;
	result.m[1][2] = z.y;
	result.m[2][2] = z.z;
	result.m[3][2] = -(vec3_dot(z, eye));
	result.m[0][3] = 0;
	result.m[1][3] = 0;
	result.m[2][3] = 0;
	result.m[3][3] = 1.0f;
	return (result);
}

t_mat4		mat_build_proj(float fov, float aspect, float near, float far)
{
	t_mat4	result;
	float	y_scale;
	float	x_scale;
	float	nearmfar;

	result = mat_init(0);
	y_scale = 1.0f / tanf((M_PI / 180.0f) * fov / 2);
	x_scale = y_scale / aspect;
	nearmfar = near - far;
	result.m[0][0] = x_scale;
	result.m[1][1] = y_scale;
	result.m[2][2] = (far + near) / nearmfar;
	result.m[2][3] = -1;
	result.m[3][2] = 2 * far * near / nearmfar;
	return (result);
}

t_mat4		mat_init(float val)
{
	t_mat4	result;

	result.m[0][0] = val;
	result.m[1][0] = val;
	result.m[2][0] = val;
	result.m[3][0] = val;
	result.m[0][1] = val;
	result.m[1][1] = val;
	result.m[2][1] = val;
	result.m[3][1] = val;
	result.m[0][2] = val;
	result.m[1][2] = val;
	result.m[2][2] = val;
	result.m[3][2] = val;
	result.m[0][3] = val;
	result.m[1][3] = val;
	result.m[2][3] = val;
	result.m[3][3] = val;
	return (result);
}

t_mat4		mat_set_identity()
{
	t_mat4	result;

	result = mat_init(0);
	result.m[0][0] = 1;
	result.m[1][1] = 1;
	result.m[2][2] = 1;
	result.m[3][3] = 1;
	return (result);
}