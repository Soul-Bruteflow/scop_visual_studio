#include "scop.h"

void	init_key(t_scop *scop)
{
	scop->scale_factor = 1.0f;
	scop->move_fac = vec3_set(0.0f, 0.0f, 0.0f);
	scop->rot_x_fac = 0.0f;
	scop->rot_y_fac = 0.0f;
	scop->rot_z_fac = 0.0f;
	scop->rot_a_fac = 0.0f;
	scop->min = vec3_set(0.0f, 0.0f, 0.0f);
	scop->max = vec3_set(0.0f, 0.0f, 0.0f);
	scop->object_center = vec3_set(0.0f, 0.0f, 0.0f);
	scop->object_back = vec3_set(0.0f, 0.0f, 0.0f);
	scop->enable_rotate = 1;
	scop->time = 0.0f;
	scop->old_time = 0.0f;
	scop->is_draw_lines = -1;
	scop->color_mode_1 = 0;
	scop->color_mode_2 = 0;
	scop->color_mode_3 = 0;
	scop->color_mode_4 = 0;
	scop->color_mode_5 = 0;
	scop->color_mode_6 = 0;
	scop->color_mode_7 = 0;
	scop->cur_tex_num = 0;
	scop->bgrd_col = vec3_set(0.0f, 0.0f, 0.0f);
	scop->eye = vec3_set(0.0f, 0.0f, -7.0f);
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
		scop->scale_factor -= 5.0f * scop->delta;
	}
	else if (scop->event.key.keysym.sym == SDLK_EQUALS)
	{
		if (scop->scale_factor > 5.0f)
		{
			scop->scale_factor = 5.0f;
			return ;
		}
		scop->scale_factor += 5.0f * scop->delta;
	}
}

void	translate_mesh(t_scop *scop)
{
	if (scop->event.key.keysym.sym == SDLK_UP)
		scop->move_fac.y += translate_move(scop->move_fac.y, 1, scop->delta);
	if (scop->event.key.keysym.sym == SDLK_DOWN)
		scop->move_fac.y -= translate_move(scop->move_fac.y, -1, scop->delta);
	if (scop->event.key.keysym.sym == SDLK_LEFT)
		scop->move_fac.x += translate_move(scop->move_fac.x, 1, scop->delta);
	if (scop->event.key.keysym.sym == SDLK_RIGHT)
		scop->move_fac.x -= translate_move(scop->move_fac.x, -1, scop->delta);
	if (scop->event.key.keysym.sym == SDLK_m)
		scop->move_fac.z += translate_move(scop->move_fac.z, 1, scop->delta);
	if (scop->event.key.keysym.sym == SDLK_n)
		scop->move_fac.z -= translate_move(scop->move_fac.z, -1, scop->delta);
}

float	translate_move(float base_value, int flag, double delta)
{
	if (base_value >= 100.0f && flag == 1)
		return (0.0f);
	if (base_value <= -100.0f && flag == -1)
		return (0.0f);
	return (15.0f * delta);
}
