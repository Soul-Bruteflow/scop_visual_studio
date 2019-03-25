#include "scop.h"

int				main(int argc, char *argv[])
{
	t_scop		*scop;

	if (argc == 2)
	{
		scop = init_scop();
		if (load_tga(TGA_PATH_1, scop) == -1)
			return (0);
		if (init_sdl_gl(scop) == -1)
			return (0);
		init_key(scop);
		init_open_gl_attributes(scop);
		scop->obj_file_name = argv[1];
		obj_pars_main(scop);
		load_shaders(scop);
		send_texture_to_opengl(scop);
		main_colors(scop);
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

void			send_texture_to_opengl(t_scop *scop)
{
	glGenTextures(1, &scop->texture_id);
	glBindTexture(GL_TEXTURE_2D, scop->texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, scop->tga_width,
				scop->tga_height, 0, GL_RGB, GL_UNSIGNED_BYTE,
				scop->tga_image_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
}