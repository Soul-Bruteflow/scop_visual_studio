#include "scop.h"

unsigned int		ft_2d_str_count(const char **str)
{
	unsigned int	element_count;

	element_count = 0;
	while (str[element_count])
		element_count++;
	return (element_count);
}