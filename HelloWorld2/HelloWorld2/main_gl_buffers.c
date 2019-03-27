/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gl_buffers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:23 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:50:23 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_gl_buffers(t_scop *scop)
{
	glGenBuffers(BUFF_COUNT, &scop->buffers);
	create_index_buffer(scop);
	create_vertices_buffer(scop);
	create_colors_buffer(scop);
}

void	create_index_buffer(t_scop *scop)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, &scop->buffers[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)
				* scop->indic_num, scop->indic, GL_STATIC_DRAW);
}

void	create_vertices_buffer(t_scop *scop)
{
	scop->buffers_idx[0] = 0;
	glBindBuffer(GL_ARRAY_BUFFER, &scop->buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)
				* scop->vert_num, scop->verts, GL_STATIC_DRAW);
	glVertexAttribPointer(scop->buffers_idx[0],
						 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(scop->buffers_idx[0]);
}

void	create_colors_buffer(t_scop *scop)
{
	scop->buffers_idx[1] = 1;
	glBindBuffer(GL_ARRAY_BUFFER, &scop->buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, (sizeof(float) * (scop->vert_num
				+ (scop->vert_num / 3))), scop->colors, GL_STATIC_DRAW);
	glVertexAttribPointer(scop->buffers_idx[1], 4, GL_FLOAT,
						 GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(scop->buffers_idx[1]);
}