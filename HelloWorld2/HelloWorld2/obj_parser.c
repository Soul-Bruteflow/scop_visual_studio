#include "scop.h"

void		obj_pars_main(t_scop *scop)
{
	if (is_obj(scop) == -1)
		return ;
	vertices_pars(scop);
}

void		vertices_pars(t_scop *scop)
{
	printf("Success\n");
	vertices_count(scop);
	vertices_allocate_mem(scop);
	vertices_write(scop);
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
