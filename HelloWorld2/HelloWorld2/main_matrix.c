#include "scop.h"

void		main_matrix(t_scop *scop)
{
	set_view(scop);
	set_projection(scop);
	glUseProgram(scop->shdr_prog);
	scop->view_id = glGetUniformLocation(scop->shdr_prog, "view");
	scop->proj_id = glGetUniformLocation(scop->shdr_prog, "proj");
	glUniformMatrix4fv(scop->view_id, 1, GL_FALSE, scop->view.m);
	glUniformMatrix4fv(scop->proj_id, 1, GL_FALSE, scop->proj.m);
	glUseProgram(0);
}

void		set_view(t_scop *scop)
{
	scop->up = vec3_set(0.0f, 1.0f, 0.0f);
	scop->center = vec3_set(0.0f, 0.0f, 0.0f);
	scop->view = mat_build_view(scop->eye, scop->center, scop->up);
}

void		set_projection(t_scop *scop)
{
	scop->fov = 90.0f;
	scop->near = 0.01f;
	scop->far = 50.0f;
	scop->asp = WINX / WINY;
	scop->proj = mat_build_proj(scop->fov, scop->asp, scop->near, scop->far);
}