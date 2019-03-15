#include "scop.h"

int				main(int argc, char *argv[])
{
	t_scop		*scop;

	if (argc == 2)
	{
		scop = init_scop();
		if (init_sdl_gl(scop) == -1)
			return (0);
		init_open_gl_attributes();
		scop->obj_file_name = argv[1];
		obj_pars_main(scop);
		load_shaders(scop);
		main_loop(scop);
	}
	cleanup_sdl(scop);
	return (0);
}