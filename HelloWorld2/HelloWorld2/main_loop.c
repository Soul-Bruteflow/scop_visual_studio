#include "scop.h"

void	main_loop(t_scop *scop)
{
	int quit;

	quit = 0;
	while (quit != -1)
	{
		while (SDL_PollEvent(&scop->event))
		{
			if (scop->event.type == SDL_QUIT)
				quit = -1;
			quit = key_down(scop);
		}
		scop->old_time = scop->time;
		scop->time = SDL_GetTicks();
		scop->delta = (scop->time - scop->old_time) / 1000.0f;
		auto_rotate(scop);
		main_render(scop);
	}
}

int		key_down(t_scop *scop)
{
	if (scop->event.type == SDL_KEYDOWN)
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
		if (scop->event.key.keysym.sym == SDLK_ESCAPE)
			return (-1);
		scale_mesh(scop);
		translate_mesh(scop);
		rotate_x(scop);
		rotate_y(scop);
		rotate_z(scop);
	}
	return (0);
}
