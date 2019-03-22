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
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(unsigned int)
	* scop->indices_count * 3), scop->indices, GL_STATIC_DRAW);
}

void	create_vertices_buffer(t_scop *scop)
{
	scop->buffers_idx[0] = 0;
	glBindBuffer(GL_ARRAY_BUFFER, &scop->buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, (sizeof(float) * scop->vertices_count * 3), scop->vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(scop->buffers_idx[0], 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(scop->buffers_idx[0]);
}

void	create_colors_buffer(t_scop *scop)
{
	scop->buffers_idx[1] = 1;
	glBindBuffer(GL_ARRAY_BUFFER, &scop->buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, (sizeof(float) * scop->vertices_count * 4), scop->colors, GL_STATIC_DRAW);
	glVertexAttribPointer(scop->buffers_idx[1], 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(scop->buffers_idx[1]);
}
