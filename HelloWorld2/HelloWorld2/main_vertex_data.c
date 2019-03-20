#include "scop.h"

void	main_vertex_data(t_scop *scop)
{
	set_up_vertex_data(scop);
}

void	set_up_vertex_data(t_scop *scop)
{
	glGenVertexArrays(1, &scop->vao);
	glGenBuffers(1, &scop->vbo);
	glGenBuffers(1, &scop->ebo);
	glBindVertexArray(scop->vao);
	glBindBuffer(GL_ARRAY_BUFFER, scop->vbo);
	glBufferData(GL_ARRAY_BUFFER, (sizeof(float) * scop->vertices_count * 3),
				scop->vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(unsigned int) *
				scop->indices_count * 3), scop->indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 *
							sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	// uncomment this call to draw in wireframe polygons.
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}