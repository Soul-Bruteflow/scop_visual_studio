#include "scop.h"

void	togle_color_mod_3(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_4)
	{
		if (scop->color_mode_3 == 1)
		{
			scop->color_mode_3 = 0;
		}
		else
			scop->color_mode_3 = 1;
	}
	printf("%d\n", scop->color_mode_3);
}

void	togle_color_mod_4(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_5)
	{
		if (scop->color_mode_4 == 1)
		{
			scop->color_mode_4 = 0;
		}
		else
			scop->color_mode_4 = 1;
	}
}