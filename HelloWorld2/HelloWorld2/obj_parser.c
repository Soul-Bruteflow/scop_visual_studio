#include "scop.h"

void		obj_pars_main(t_scop *scop)
{
	count_vertices(scop);
	allocate_vetrex_mem(scop);
	write_vertices(scop);

}