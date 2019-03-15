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
	}
}

int		key_down(t_scop *scop)
{
	if (scop->event.type == SDL_KEYDOWN)
	{
		if (scop->event.key.keysym.sym == SDLK_ESCAPE)
		return (-1);
	}
	return (0);
}
