#include "scop.h"

int				main(int argc, char *argv[])
{
	t_scop		*scop;

	if (argc == 2)
	{
		scop = init_scop();
		scop->obj_file_name = argv[1];
		obj_pars_main(scop);
	}
	return (0);
}

t_scop			*init_scop()
{
	t_scop		*tmp;
	
	tmp = malloc(sizeof(t_scop));
	return (tmp);
}
