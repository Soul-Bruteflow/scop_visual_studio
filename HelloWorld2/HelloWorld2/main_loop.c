/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:27 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:50:27 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	main_loop(t_scop *scop)
{
	int	quit;

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
		move_camera(scop);
		change_background_color(scop);
		toggle(scop);
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

void	toggle(t_scop *scop)
{
	togle_draw_lines(scop);
	togle_auto_rotate(scop);
	togle_color_mod_1(scop);
	togle_color_mod_2(scop);
	togle_color_mod_3(scop);
	togle_color_mod_4(scop);
	togle_color_mod_5(scop);
	togle_color_mod_6(scop);
	togle_color_mod_7(scop);
	togle_color_refresh(scop);
}