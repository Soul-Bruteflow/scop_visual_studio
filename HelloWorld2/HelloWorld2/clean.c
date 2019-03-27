/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:48:07 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:48:07 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	cleanup_sdl(t_scop *scop)
{
	SDL_GL_DeleteContext(scop->main_context);
	SDL_DestroyWindow(scop->main_window);
	SDL_Quit();
}