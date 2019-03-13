#include "scop.h"

void		count_vertices(t_scop *scop)
{
	int		fd;
	char	*line;

	scop->vetrex_count = 0;
	fd = open(scop->obj_file_name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'v' && line[1] == ' ')
			scop->vetrex_count++;
		free(line);
	}
}

void		allocate_vetrex_mem(t_scop *scop)
{
	scop->vertices = malloc(sizeof(float) * scop->vetrex_count * 3);
}

void		write_vertices(t_scop *scop)
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
			//printf("%f\n", scop->vertices[0]);
			//printf("%d\n", scop->i + 0);

			scop->vertices[scop->i + 1] = ft_atof(splited_values[1]);
			//printf("%f\n", scop->vertices[1]);
			//printf("%d\n", scop->i + 1);

			scop->vertices[scop->i + 2] = ft_atof(splited_values[2]);
			//printf("%f\n", scop->vertices[2]);
			//printf("%d\n", scop->i + 2);

			scop->i += 3;
			//printf("%d\n", scop->i);
			free(splited_values);
		}
		free(line);
	}
}