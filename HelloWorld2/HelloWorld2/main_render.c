#include "scop.h"

void	main_render(t_scop *scop)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(scop->shdr_prog);
	set_model_mats(scop);
	transfer_matrices_to_gpu(scop);
	transfer_key_mods_to_gpu(scop);
	glDrawElements(GL_TRIANGLES, scop->indices_count * 3, GL_UNSIGNED_INT, 0);
	SDL_GL_SwapWindow(scop->main_window);
}

void	transfer_matrices_to_gpu(t_scop *scop)
{
	scop->scale_id = glGetUniformLocation(scop->shdr_prog, "scale");
	glUniformMatrix4fv(scop->scale_id, 1, GL_FALSE, scop->scale.m);
	scop->trans_id = glGetUniformLocation(scop->shdr_prog, "translate");
	glUniformMatrix4fv(scop->trans_id, 1, GL_FALSE, scop->translate.m);
	scop->rotate_x_id = glGetUniformLocation(scop->shdr_prog, "rotate_x");
	glUniformMatrix4fv(scop->rotate_x_id, 1, GL_FALSE, scop->rotate_x.m);
	scop->rotate_y_id = glGetUniformLocation(scop->shdr_prog, "rotate_y");
	glUniformMatrix4fv(scop->rotate_y_id, 1, GL_FALSE, scop->rotate_y.m);
	scop->rotate_z_id = glGetUniformLocation(scop->shdr_prog, "rotate_z");
	glUniformMatrix4fv(scop->rotate_z_id, 1, GL_FALSE, scop->rotate_z.m);
	scop->trans_cent_id = glGetUniformLocation(scop->shdr_prog, "trans_cent");
	glUniformMatrix4fv(scop->trans_cent_id, 1, GL_FALSE, scop->trans_cent.m);
	scop->trans_back_id = glGetUniformLocation(scop->shdr_prog, "trans_back");
	glUniformMatrix4fv(scop->trans_back_id, 1, GL_FALSE, scop->trans_back.m);
}

void	transfer_key_mods_to_gpu(t_scop *scop)
{
	scop->mods_id_1 = glGetUniformLocation(scop->shdr_prog, "color_mode_1");
	glUniform1i(scop->mods_id_1, scop->color_mode_1);

	scop->mods_id_2 = glGetUniformLocation(scop->shdr_prog, "color_mode_2");
	glUniform1i(scop->mods_id_2, scop->color_mode_2);

	scop->mods_id_2_1 = glGetUniformLocation(scop->shdr_prog, "color_mode_2_1");
	glUniform1i(scop->mods_id_2_1, scop->color_mode_2);

	scop->mods_id_3 = glGetUniformLocation(scop->shdr_prog, "color_mode_3");
	glUniform1i(scop->mods_id_3, scop->color_mode_3);

	scop->mods_id_4 = glGetUniformLocation(scop->shdr_prog, "color_mode_4");
	glUniform1i(scop->mods_id_4, scop->color_mode_4);

	scop->mods_id_3_1 = glGetUniformLocation(scop->shdr_prog, "color_mode_3_1");
	glUniform1i(scop->mods_id_3_1, scop->color_mode_3);

	scop->mods_id_4_1 = glGetUniformLocation(scop->shdr_prog, "color_mode_4_1");
	glUniform1i(scop->mods_id_4_1, scop->color_mode_4);
}
