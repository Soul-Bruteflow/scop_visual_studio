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

	fd = open(scop->obj_file_name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			splited_values = ft_strsplit(&line[2], ' ');
			printf("%s\n", splited_values[0]);
			free(splited_values);
		}
		//printf("%s\n", line);
		//ft_putendl(line);
		free(line);
	}
}