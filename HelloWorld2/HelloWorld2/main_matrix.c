#include "scop.h"

void		main_matrix(t_scop *scop)
{
	set_camera(scop);
	glUseProgram(scop->shader_program);
	scop->camera_id = glGetUniformLocation(scop->shader_program, "camera");
	glUniformMatrix4fv(scop->camera_id, 1, GL_FALSE, scop->camera.m);
	glUseProgram(0);
}

void		set_camera(t_scop *scop)
{
	scop->up = vec3_set(0.0f, 1.0f, 0.0f);
	scop->center = vec3_set(0.0f, 0.0f, 0.0f);
	scop->eye = vec3_set(3.0f, 3.0f, 3.0f);
	scop->camera = mat_build_view(scop->eye, scop->center, scop->up);
}