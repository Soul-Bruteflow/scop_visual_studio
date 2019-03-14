#include "scop.h"

void		indices_count(t_scop *scop)
{
	int		fd;
	char	*line;
	char	**splited_values;
	int		element_count;

	scop->indices_count = 0;
	fd = open(scop->obj_file_name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'f' && line[1] == ' ')
		{
			scop->indices_count++;
			splited_values = ft_strsplit(&line[2], ' ');
			element_count = ft_2d_str_count(splited_values);
			if (element_count == 4)
				scop->indices_count++;
			else if (element_count > 4)
				return ;
			free(splited_values);
		}
		free(line);
	}
}

void		indices_allocate_mem(t_scop *scop)
{
	scop->indices = malloc(sizeof(unsigned int) * scop->indices_count * 3);
}

void		indices_write(t_scop *scop)
{
	int		fd;
	char	*line;
	char	**splited_values;
	int		element_count;

	scop->i = 0;
	fd = open(scop->obj_file_name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'f' && line[1] == ' ')
		{
			splited_values = ft_strsplit(&line[2], ' ');
			element_count = ft_2d_str_count(splited_values);
			if (element_count == 3)
				indices_write_three(scop, splited_values);
			else if (element_count == 4)
				indices_write_four(scop, splited_values);
			free(splited_values);
		}
		free(line);
	}
}

void		indices_write_three(t_scop *scop, char	**splited_values)
{
	scop->indices[scop->i + 0] = ft_atoi(splited_values[0]);
	scop->indices[scop->i + 1] = ft_atoi(splited_values[1]);
	scop->indices[scop->i + 2] = ft_atoi(splited_values[2]);
	scop->i += 3;
}

void		indices_write_four(t_scop *scop, char	**splited_values)
{
	scop->indices[scop->i + 0] = ft_atoi(splited_values[0]);
	scop->indices[scop->i + 1] = ft_atoi(splited_values[1]);
	scop->indices[scop->i + 2] = ft_atoi(splited_values[2]);
	scop->indices[scop->i + 3] = ft_atoi(splited_values[0]);
	scop->indices[scop->i + 4] = ft_atoi(splited_values[2]);
	scop->indices[scop->i + 5] = ft_atoi(splited_values[3]);
	scop->i += 6;
}
