#include "scop.h"

void	main_colors(t_scop *scop)
{
	colors_allocate_mem(scop);
	generate_random_colors(scop);
}

void		colors_allocate_mem(t_scop *scop)
{
	scop->colors = malloc(sizeof(float) * scop->vertices_count * 4);
}

void	generate_random_colors(t_scop *scop)
{
	unsigned int i;

	i = 0;
	while (i < scop->vertices_count * 4)
	{
		scop->colors[i + 0] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		scop->colors[i + 1] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		scop->colors[i + 2] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		scop->colors[i + 3] = 1.0f;
		i += 4;
	}
}
