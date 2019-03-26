#include "scop.h"

int		obj_pars_main(t_scop *scop)
{
	if (is_obj(scop) == -1)
		return (-1);
	if (read_wtire_v_f(scop) == -1)
		return (-1);
	find_min_max(scop);
	generate_uv(scop);
	return (1);
}

int			read_wtire_v_f(t_scop *scop)
{
	int		fd;
	char	*line;
	int		cap;
	int		cap2;

	cap = 3;
	cap2 = 6;
	scop->vert_num = 0;
	scop->indices_count = 0;
	if ((fd = open(scop->obj_file_name, O_RDONLY)) < 0)
		return (-1);
	scop->verts = (float*)malloc(sizeof(float) * cap);
	scop->indices = (unsigned int*)malloc(sizeof(unsigned int) * cap2);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'v' && line[1] == ' ')
			cap = vertices_write(scop, cap, line);
		else if (line[0] == 'f' && line[1] == ' ')
			cap2 = indices_write(scop, cap2, line);
		free(line);
	}
	scop->verts = (float*)realloc(scop->verts, scop->vert_num * sizeof(float));
	scop->indices = (unsigned int*)realloc(scop->indices, scop->indices_count * sizeof(unsigned int));
	close(fd);
	return (1);
}

int			vertices_write(t_scop *scop, int cap, char *line)
{
	char	**split_vals;

	split_vals = ft_strsplit(&line[2], ' ');
	scop->verts[scop->vert_num + 0] = ft_atof(split_vals[0]);
	scop->verts[scop->vert_num + 1] = ft_atof(split_vals[1]);
	scop->verts[scop->vert_num + 2] = ft_atof(split_vals[2]);
	scop->vert_num += 3;
	free(split_vals);
	if (scop->vert_num == cap)
	{
		cap *= 2;
		scop->verts = (float*)realloc(scop->verts, cap * sizeof(float));
	}
	return (cap);
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

void		find_min_max(t_scop *scop)
{
	scop->i = 0;
	while (scop->i < scop->vert_num)
	{
		if (scop->verts[scop->i + 0] < scop->min.x)
			scop->min.x = scop->verts[scop->i + 0];
		if (scop->verts[scop->i + 0] > scop->max.x)
			scop->max.x = scop->verts[scop->i + 0];
		if (scop->verts[scop->i + 1] < scop->min.y)
			scop->min.y = scop->verts[scop->i + 1];
		if (scop->verts[scop->i + 1] > scop->max.y)
			scop->max.y = scop->verts[scop->i + 1];
		if (scop->verts[scop->i + 2] < scop->min.z)
			scop->min.z = scop->verts[scop->i + 2];
		if (scop->verts[scop->i + 2] > scop->max.z)
			scop->max.z = scop->verts[scop->i + 2];
		scop->i += 3;
	}
	scop->object_center.x = -(scop->min.x + scop->max.x) / 2.0f;
	scop->object_center.y = -(scop->min.y + scop->max.y) / 2.0f;
	scop->object_center.z = -(scop->min.z + scop->max.z) / 2.0f;
	scop->object_back.x = (scop->min.x + scop->max.x) / 2.0f;
	scop->object_back.y = (scop->min.y + scop->max.y) / 2.0f;
	scop->object_back.z = (scop->min.z + scop->max.z) / 2.0f;
}
