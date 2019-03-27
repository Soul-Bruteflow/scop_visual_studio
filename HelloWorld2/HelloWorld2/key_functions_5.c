#include "scop.h"

void	change_background_color(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_z)
	{
		scop->bgrd_col.x = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		scop->bgrd_col.y = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		scop->bgrd_col.z = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
	}
	if (scop->event.key.keysym.sym == SDLK_x)
	{
		scop->bgrd_col.x = 0.0f;
		scop->bgrd_col.y = 0.0f;
		scop->bgrd_col.z = 0.0f;
	}
}

void	move_camera(t_scop *scop)
{
	move_camera_z(scop);
	move_camera_x(scop);
	move_camera_y(scop);
}

void	move_camera_z(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_w)
	{
		scop->eye.z += 20.0f * scop->delta;
		set_view(scop);
	}
	if (scop->event.key.keysym.sym == SDLK_s)
	{
		scop->eye.z -= 20.0f * scop->delta;
		set_view(scop);
	}
}

void	move_camera_x(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_a)
	{
		scop->eye.x += 20.0f * scop->delta;
		set_view(scop);
	}
	if (scop->event.key.keysym.sym == SDLK_d)
	{
		scop->eye.x -= 20.0f * scop->delta;
		set_view(scop);
	}
}

void	move_camera_y(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_c)
	{
		scop->eye.y += 20.0f * scop->delta;
		set_view(scop);
	}
	if (scop->event.key.keysym.sym == SDLK_v)
	{
		scop->eye.y -= 20.0f * scop->delta;
		set_view(scop);
	}
}
