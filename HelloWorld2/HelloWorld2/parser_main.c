#include "scop.h"

void		obj_pars_main(t_scop *scop)
{
	if (is_obj(scop) == -1)
		return ;
	vertices_pars(scop);
	indices_pars(scop);
	find_min_max(scop);
	generate_uv(scop);
}

int			is_obj(t_scop *scop)
{
	size_t	len;
	char	*s;

	s = scop->obj_file_name;
	len = ft_strlen(s);
	if (s[len - 1] != 'j' && s[len - 2] != 'b' && s[len - 3] != 'o'
		&& s[len - 4] != '.')
		return (-1);
	return (0);
}

void		vertices_pars(t_scop *scop)
{
	vertices_count(scop);
	vertices_allocate_mem(scop);
	vertices_write(scop);
}

void		indices_pars(t_scop *scop)
{
	indices_count(scop);
	indices_allocate_mem(scop);
	indices_write(scop);
}

void		find_min_max(t_scop *scop)
{
	scop->i = 0;
	while (scop->i < scop->vertices_count * 3)
	{
		if (scop->vertices[scop->i + 0] < scop->min.x)
			scop->min.x = scop->vertices[scop->i + 0];
		if (scop->vertices[scop->i + 0] > scop->max.x)
			scop->max.x = scop->vertices[scop->i + 0];
		if (scop->vertices[scop->i + 1] < scop->min.y)
			scop->min.y = scop->vertices[scop->i + 1];
		if (scop->vertices[scop->i + 1] > scop->max.y)
			scop->max.y = scop->vertices[scop->i + 1];
		if (scop->vertices[scop->i + 2] < scop->min.z)
			scop->min.z = scop->vertices[scop->i + 2];
		if (scop->vertices[scop->i + 2] > scop->max.z)
			scop->max.z = scop->vertices[scop->i + 2];
		scop->i += 3;
	}
	scop->object_center.x = -(scop->min.x + scop->max.x) / 2.0f;
	scop->object_center.y = -(scop->min.y + scop->max.y) / 2.0f;
	scop->object_center.z = -(scop->min.z + scop->max.z) / 2.0f;
	scop->object_back.x = (scop->min.x + scop->max.x) / 2.0f;
	scop->object_back.y = (scop->min.y + scop->max.y) / 2.0f;
	scop->object_back.z = (scop->min.z + scop->max.z) / 2.0f;
}
