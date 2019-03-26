#include "scop.h"

int			indices_write(t_scop *scop, int cap2, char *line)
{

	char	**splited_values;
	int		element_count;

	splited_values = ft_strsplit(&line[2], ' ');
	element_count = ft_2d_str_count(splited_values);
	if (element_count == 4)
		indices_write_four(scop, splited_values);
	else
		indices_write_three(scop, splited_values);
	free(splited_values);
	if (scop->indices_count == cap2)
	{
		cap2 *= 2;
		scop->indices = (unsigned int*)realloc(scop->indices, cap2 * sizeof(unsigned int));
	}
	return (cap2);
}

void		indices_write_three(t_scop *scop, char	**splited_values)
{
	scop->indices[scop->indices_count + 0] = (ft_atoi(splited_values[0]) - 1);
	scop->indices[scop->indices_count + 1] = (ft_atoi(splited_values[1]) - 1);
	scop->indices[scop->indices_count + 2] = (ft_atoi(splited_values[2]) - 1);
	scop->indices_count += 3;
}

void		indices_write_four(t_scop *scop, char	**splited_values)
{
	scop->indices[scop->indices_count + 0] = (ft_atoi(splited_values[0]) - 1);
	scop->indices[scop->indices_count + 1] = (ft_atoi(splited_values[1]) - 1);
	scop->indices[scop->indices_count + 2] = (ft_atoi(splited_values[2]) - 1);
	scop->indices[scop->indices_count + 3] = (ft_atoi(splited_values[0]) - 1);
	scop->indices[scop->indices_count + 4] = (ft_atoi(splited_values[2]) - 1);
	scop->indices[scop->indices_count + 5] = (ft_atoi(splited_values[3]) - 1);
	scop->indices_count += 6;
}
