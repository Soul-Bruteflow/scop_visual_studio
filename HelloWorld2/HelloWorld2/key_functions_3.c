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

void	togle_color_mod_1(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_2)
	{
		if (scop->color_mode_1 == 1)
		{
			scop->color_mode_1 = 0;
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
		else
		{
			scop->color_mode_1 = 1;
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
	}
}

void	togle_color_refresh(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_r)
	{
		generate_random_colors(scop);
		create_colors_buffer(scop);
	}
}

void	togle_color_mod_2(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_3)
	{
		if (scop->color_mode_2 == 1)
		{
			scop->color_mode_1 = 0;
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
		else
		{
			scop->color_mode_1 = 0;
			scop->color_mode_2 = 1;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
	}
}
