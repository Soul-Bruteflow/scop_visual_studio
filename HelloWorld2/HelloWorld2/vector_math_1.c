#include "scop.h"

t_vec3		vec3_set(float x, float y, float z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

float		vec3_magnitude(t_vec3 v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3		vec3_normalize(t_vec3 v)
{
	float	magnitude;

	magnitude = vec3_magnitude(v);
	if (magnitude > 0)
	{
		v.x /= magnitude;
		v.y /= magnitude;
		v.z /= magnitude;
	}
	else
	{
		v.x = NAN;
		v.y = NAN;
		v.z = NAN;
	}
	return (v);
}

t_vec3		vec3_sub(t_vec3 v1, t_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec3		vec3_add(t_vec3 v1, t_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}
