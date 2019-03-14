#include "scop.h"

void		obj_pars_main(t_scop *scop)
{
	if (is_obj(scop) == -1)
		return ;
	vertices_pars(scop);
	indices_pars(scop);
	
	unsigned int i = 0;
	while (i < scop->indices_count * 3)
	{
		printf("%u\n", scop->indices[i]);
		i++;
	}
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
