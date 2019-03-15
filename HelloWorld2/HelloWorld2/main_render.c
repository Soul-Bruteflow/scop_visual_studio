#include "scop.h"

void	main_render(t_scop *scop)
{
	glUseProgram(scop->shader_program);
	glBindVertexArray(scop->vao);
	glDrawElements(GL_TRIANGLES, scop->indices_count * 3, GL_UNSIGNED_INT, 0);
	SDL_GL_SwapWindow(scop->main_window);
}