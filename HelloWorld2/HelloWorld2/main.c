#include "scop.h"

int				main(int argc, char *argv[])
{
	t_scop		*scop;

	t_vec3 v1;
	t_vec3 v2;

	v1 = vec3_set(3.0, 1.0, 4.0);
	v2 = vec3_set(5.0, -2.0, 6.0);
	//t_vec3 tmp = vec3_cross(v1, v2);

	float tmp = vec3_dot(v1, v2);
	printf("%f\n", tmp);

	//printf("%f\n", tmp.x);
	//printf("%f\n", tmp.y);
	//printf("%f\n", tmp.z);

	//if (argc == 2)
	//{
	//	scop = init_scop();
	//	if (init_sdl_gl(scop) == -1)
	//		return (0);
	//	init_open_gl_attributes();
	//	scop->obj_file_name = argv[1];
	//	obj_pars_main(scop);
	//	load_shaders(scop);
	//	main_vertex_data(scop);
	//	glClearColor(0.0, 0.0, 0.0, 1.0);
	//	glClear(GL_COLOR_BUFFER_BIT);
	//	SDL_GL_SwapWindow(scop->main_window);
	//	main_loop(scop);
	//}
	//cleanup_sdl(scop);
	return (0);
}