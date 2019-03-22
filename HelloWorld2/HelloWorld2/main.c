#include "scop.h"

int				main(int argc, char *argv[])
{
	t_scop		*scop;

	if (argc == 2)
	{
		scop = init_scop();
		if (init_sdl_gl(scop) == -1)
			return (0);
		init_key(scop);
		init_open_gl_attributes();
		scop->obj_file_name = argv[1];
		obj_pars_main(scop);
		load_shaders(scop);
		main_colors(scop);
		int i = 0;
		while (i < scop->vertices_count * 4)
		{
			printf("r: %f, ", scop->colors[i]);
			printf("g: %f, ", scop->colors[i+1]);
			printf("b: %f, ", scop->colors[i+2]);
			printf("a: %f", scop->colors[i+3]);
			i += 4;
			printf("\n");
		}
		create_gl_buffers(scop);
		main_matrix(scop);
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(scop->main_window);
		main_loop(scop);
	}
	cleanup_sdl(scop);
	return (0);
}