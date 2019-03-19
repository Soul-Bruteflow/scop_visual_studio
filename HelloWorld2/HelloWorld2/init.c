#include "scop.h"

t_scop			*init_scop()
{
	t_scop		*tmp;

	tmp = malloc(sizeof(t_scop));
	return (tmp);
}

int				init_sdl_gl(t_scop *scop)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (-1);
	scop->main_window = SDL_CreateWindow(WINNAME, SDL_WINDOWPOS_CENTERED,
						SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_OPENGL);
	if (!scop->main_window)
		return (-1);
	scop->main_context = SDL_GL_CreateContext(scop->main_window);
	init_open_gl_attributes();
	SDL_GL_SetSwapInterval(1);
	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit())
		return (-1);
	glViewport(0, 0, WINX, WINY);
	return (0);
}

void			init_open_gl_attributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
						SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS);
}
