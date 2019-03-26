#include "scop.h"

void	togle_color_mod_3(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_4)
	{
		if (scop->color_mode_3 == 1)
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
			scop->color_mode_3 = 1;
	}
}

void	togle_color_mod_4(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_5)
	{
		if (scop->color_mode_4 == 1)
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
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 1;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
	}
}

void	togle_color_mod_5(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_6)
	{
		if (scop->color_mode_5 == 1)
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
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 1;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 0;
		}
	}
}

void	togle_color_mod_6(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_7)
	{
		if (scop->color_mode_6 == 1)
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
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 1;
			scop->color_mode_7 = 0;
		}
	}
}

void	togle_color_mod_7(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_8)
	{
		if (scop->color_mode_7 == 1)
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
			scop->color_mode_2 = 0;
			scop->color_mode_3 = 0;
			scop->color_mode_4 = 0;
			scop->color_mode_5 = 0;
			scop->color_mode_6 = 0;
			scop->color_mode_7 = 1;
		}
	}
}