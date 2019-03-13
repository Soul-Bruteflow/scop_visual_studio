#include "scop.h"

void		obj_pars_main(t_scop *scop)
{
	vertecies_pars(scop);
	int i = 0;

	while (i < scop->vetrex_count * 3)
	{
		printf("%f\n", scop->vertices[i]);
		i++;
	}
}

void		vertecies_pars(t_scop *scop)
{
	count_vertices(scop);
	allocate_vetrex_mem(scop);
	write_vertices(scop);
}