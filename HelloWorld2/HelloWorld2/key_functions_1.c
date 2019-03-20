#include "scop.h"

void	init_key(t_scop *scop)
{
	scop->scale_factor = 1.0f;
	scop->translate_factor = vec3_set(0.0f, 0.0f, 0.0f);
	scop->rotate_x = 0.0f;
}

void	scale_mesh(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_MINUS)
	{
		if (scop->scale_factor < 0.1f)
		{
			scop->scale_factor = 0.1f;
			return ;
		}
		scop->scale_factor -= 0.01f;
	}
	else if (scop->event.key.keysym.sym == SDLK_EQUALS)
	{
		if (scop->scale_factor > 5.0f)
		{
			scop->scale_factor = 5.0f;
			return ;
		}
		scop->scale_factor += 0.01f;
	}
}

void	translate_mesh(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_UP)
		scop->translate_factor.y += translate_move(scop->translate_factor.y, 1);
	if (scop->event.key.keysym.sym == SDLK_DOWN)
		scop->translate_factor.y -= translate_move(scop->translate_factor.y, -1);
	if (scop->event.key.keysym.sym == SDLK_LEFT)
		scop->translate_factor.x += translate_move(scop->translate_factor.x, 1);
	if (scop->event.key.keysym.sym == SDLK_RIGHT)
		scop->translate_factor.x -= translate_move(scop->translate_factor.x, -1);
	if (scop->event.key.keysym.sym == SDLK_m)
		scop->translate_factor.z += translate_move(scop->translate_factor.z, 1);
	if (scop->event.key.keysym.sym == SDLK_n)
		scop->translate_factor.z -= translate_move(scop->translate_factor.z, -1);
}

float	translate_move(float base_value, int flag)
{
	if (base_value >= 50.0f && flag == 1)
		return (0.0f);
	if (base_value <= -50.0f && flag == -1)
		return (0.0f);
	return (1.0f);
}

void	rotate_x(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_w)
	{
		if (scop->rotate_x == 360.0f)
		{
			scop->rotate_x = 1.0f;
			return;
		}
		scop->rotate_x += 1.0f;
	}
	if (scop->event.key.keysym.sym == SDLK_s)
	{
		if (scop->rotate_x == -360.0f)
		{
			scop->rotate_x = -1.0f;
				return;
		}
		scop->rotate_x -= 1.0f;
	}
	printf("%f\n", scop->rotate_x);
}
