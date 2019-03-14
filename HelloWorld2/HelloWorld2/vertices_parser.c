#include "scop.h"

void		vertices_count(t_scop *scop)
{
	int		fd;
	char	*line;

	scop->vertices_count = 0;
	fd = open(scop->obj_file_name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'v' && line[1] == ' ')
			scop->vertices_count++;
		free(line);
	}
}

void		vertices_allocate_mem(t_scop *scop)
{
	scop->vertices = malloc(sizeof(float) * scop->vertices_count * 3);
}

void		vertices_write(t_scop *scop)
{
	int		fd;
	char	*line;
	char	**splited_values;

	scop->i = 0;
	fd = open(scop->obj_file_name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			splited_values = ft_strsplit(&line[2], ' ');
			scop->vertices[scop->i + 0] = ft_atof(splited_values[0]);
			scop->vertices[scop->i + 1] = ft_atof(splited_values[1]);
			scop->vertices[scop->i + 2] = ft_atof(splited_values[2]);
			scop->i += 3;
			free(splited_values);
		}
		free(line);
	}
}
