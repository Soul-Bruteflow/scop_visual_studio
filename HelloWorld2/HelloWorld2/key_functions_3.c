#include "scop.h"

void	togle_auto_rotate(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_SPACE)
	{
		if (scop->enable_rotate == 1)
		{
			scop->enable_rotate = -1;
			scop->copy_auto = 1;
		}
		else
		{
			scop->enable_rotate = 1;
			scop->rot_a_fac = scop->rot_x_fac;
		}
	}
}

void	togle_draw_lines(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_1)
	{
		if (scop->is_draw_lines == 1)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			scop->is_draw_lines = -1;
		}
		else
		{
			scop->is_draw_lines = 1;
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
	}
}
