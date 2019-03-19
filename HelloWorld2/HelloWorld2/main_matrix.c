#include "scop.h"

void		main_matrix(t_scop *scop)
{
	set_view(scop);
	set_projection(scop);
	glUseProgram(scop->shader_program);
	scop->view_id = glGetUniformLocation(scop->shader_program, "view");
	scop->proj_id = glGetUniformLocation(scop->shader_program, "proj");
	glUniformMatrix4fv(scop->view_id, 1, GL_FALSE, scop->view.m);
	glUniformMatrix4fv(scop->proj_id, 1, GL_FALSE, scop->proj.m);
	glUseProgram(0);
}

void		set_view(t_scop *scop)
{
	scop->up = vec3_set(0.0f, 1.0f, 0.0f);
	scop->center = vec3_set(0.0f, 0.0f, 0.0f);
	scop->eye = vec3_set(3.0f, 3.0f, 3.0f);
	scop->view = mat_build_view(scop->eye, scop->center, scop->up);
}

void		set_projection(t_scop *scop)
{
	scop->fov = 90.0f;
	scop->near = 0.1f;
	scop->far = 20.0f;
	scop->asp = WINX / WINY;
	scop->proj = mat_build_proj(scop->fov, scop->asp, scop->near, scop->far);
}