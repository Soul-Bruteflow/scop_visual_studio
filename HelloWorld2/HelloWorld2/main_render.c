#include "scop.h"

void	main_render(t_scop *scop)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(scop->shader_program);
	set_model(scop);
	scop->scale_id = glGetUniformLocation(scop->shader_program, "scale");
	glUniformMatrix4fv(scop->scale_id, 1, GL_FALSE, scop->scale.m);
	scop->trans_id = glGetUniformLocation(scop->shader_program, "translate");
	glUniformMatrix4fv(scop->trans_id, 1, GL_FALSE, scop->translate.m);
	scop->rotate_id = glGetUniformLocation(scop->shader_program, "rotate");
	glUniformMatrix4fv(scop->rotate_id, 1, GL_FALSE, scop->rotate.m);

	scop->translate_cent_id = glGetUniformLocation(scop->shader_program, "translate_cent");
	glUniformMatrix4fv(scop->translate_cent_id, 1, GL_FALSE, scop->translate_cent.m);

	scop->translate_back_id = glGetUniformLocation(scop->shader_program, "translate_back");
	glUniformMatrix4fv(scop->translate_back_id, 1, GL_FALSE, scop->translate_back.m);
	glBindVertexArray(scop->vao);
	glDrawElements(GL_TRIANGLES, scop->indices_count * 3, GL_UNSIGNED_INT, 0);
	SDL_GL_SwapWindow(scop->main_window);
}