#include "scop.h"

void	rotate_x(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_u)
	{
		if (scop->rotate_x_factor == 360.0f)
		{
			scop->rotate_x_factor = 2.0f;
			return;
		}
		scop->rotate_x_factor += 2.0f;
	}
	if (scop->event.key.keysym.sym == SDLK_j)
	{
		if (scop->rotate_x_factor == -360.0f)
		{
			scop->rotate_x_factor = -2.0f;
			return;
		}
		scop->rotate_x_factor -= 2.0f;
	}
}

void	rotate_y(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_i)
	{
		if (scop->rotate_y_factor == 360.0f)
		{
			scop->rotate_y_factor = 2.0f;
			return;
		}
		scop->rotate_y_factor += 2.0f;
	}
	if (scop->event.key.keysym.sym == SDLK_k)
	{
		if (scop->rotate_y_factor == -360.0f)
		{
			scop->rotate_y_factor = -2.0f;
			return;
		}
		scop->rotate_y_factor -= 2.0f;
	}
}

void	rotate_z(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_o)
	{
		if (scop->rotate_z_factor == 360.0f)
		{
			scop->rotate_z_factor = 2.0f;
			return;
		}
		scop->rotate_z_factor += 2.0f;
	}
	if (scop->event.key.keysym.sym == SDLK_l)
	{
		if (scop->rotate_z_factor == -360.0f)
		{
			scop->rotate_z_factor = -2.0f;
			return;
		}
		scop->rotate_z_factor -= 2.0f;
	}
}
