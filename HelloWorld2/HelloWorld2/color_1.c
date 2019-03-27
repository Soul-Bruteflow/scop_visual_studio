/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:48:20 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:48:20 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				main_colors(t_scop *scop)
{
	colors_allocate_mem(scop);
	generate_random_colors(scop);
}

void				colors_allocate_mem(t_scop *scop)
{
	unsigned int	size;

	size = sizeof(float) * (scop->vert_num + (scop->vert_num / 3));
	scop->colors = malloc(size);
}

void				generate_random_colors(t_scop *scop)
{
	unsigned int	i;

	i = 0;
	while (i < (scop->vert_num + (scop->vert_num / 3)))
	{
		scop->colors[i + 0] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		scop->colors[i + 1] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		scop->colors[i + 2] = ((float)rand() / (float)(RAND_MAX)) * 1.0f;
		scop->colors[i + 3] = 1.0f;
		i += 4;
	}
}