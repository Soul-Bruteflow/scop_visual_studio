#include "scop.h"

void cleanup_sdl(t_scop *scop)
{
	SDL_GL_DeleteContext(scop->main_context);
	SDL_DestroyWindow(scop->main_window);
	SDL_Quit();
}