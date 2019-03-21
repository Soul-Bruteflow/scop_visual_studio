#include "scop.h"

void	rotate_x(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_u)
	{
		if (scop->rot_x_fac == 360.0f)
		{
			scop->rot_x_fac = 2.0f;
			return ;
		}
		scop->rot_x_fac += 2.0f;
	}
	if (scop->event.key.keysym.sym == SDLK_j)
	{
		if (scop->rot_x_fac == -360.0f)
		{
			scop->rot_x_fac = -2.0f;
			return ;
		}
		scop->rot_x_fac -= 2.0f;
	}
}

void	rotate_y(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_i)
	{
		if (scop->rot_y_fac == 360.0f)
		{
			scop->rot_y_fac = 2.0f;
			return ;
		}
		scop->rot_y_fac += 2.0f;
	}
	if (scop->event.key.keysym.sym == SDLK_k)
	{
		if (scop->rot_y_fac == -360.0f)
		{
			scop->rot_y_fac = -2.0f;
			return ;
		}
		scop->rot_y_fac -= 2.0f;
	}
}

void	rotate_z(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_o)
	{
		if (scop->rot_z_fac == 360.0f)
		{
			scop->rot_z_fac = 2.0f;
			return ;
		}
		scop->rot_z_fac += 2.0f;
	}
	if (scop->event.key.keysym.sym == SDLK_l)
	{
		if (scop->rot_z_fac == -360.0f)
		{
			scop->rot_z_fac = -2.0f;
			return ;
		}
		scop->rot_z_fac -= 2.0f;
	}
}

void	auto_rotate(t_scop *scop)
{
	if (scop->rot_a_fac >= 360.0f)
		scop->rot_a_fac = 0.0f;
	if (scop->enable_rotate == 1)
		scop->rot_a_fac += 20.0f * scop->delta;
	printf("%f\n", scop->rot_a_fac);
}
