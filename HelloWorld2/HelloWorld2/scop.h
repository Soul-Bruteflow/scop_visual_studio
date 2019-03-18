#ifndef SCOP_H
# define SCOP_H

/*
** External libs
*/
# include				<math.h>
# include				<stdio.h>
# include				<stdlib.h>
# include				<fcntl.h>
# include				<SDL.h>
# include				<GL/glew.h>
# include				<SDL_opengl.h>

/*
** Custom libs
*/
# include				"libft\libft.h"
# include				"get_next_line.h"

/*
** Defines
*/
# define WINX			800
# define WINY			600
# define WINNAME		"scop"
# define VERT_PATH		"shader_vertex.glsl"
# define FRAG_PATH		"shader_fragment.glsl"

/*
** Math structs
*/
typedef struct			s_mat4
{
	float				m[4][4];
}						t_mat4;

typedef struct			s_vec3
{
	float				x;
	float				y;
	float				z;
}						t_vec3;

typedef struct			s_vec4
{
	float				x;
	float				y;
	float				z;
	float				w;
}						t_vec4;

/*
** Main data structure
*/
typedef struct			s_scop
{
	SDL_Window			*main_window;
	SDL_GLContext		main_context;
	SDL_Event			event;
	char				*obj_file_name;
	unsigned int		vertices_count;
	unsigned int		indices_count;
	float				*vertices;
	unsigned int		*indices;
	int					i;
	int					vertex_shader;
	int					fragment_shader;
	int					shader_program;
	char				*vertex_shdr_src;
	char				*fragment_shdr_src;
	unsigned int		vbo;
	unsigned int		ebo;
	unsigned int		vao;
	t_vec3				up;
	t_vec3				eye;
	t_vec3				center;
	t_mat4				camera;
	int					camera_id;
}						t_scop;

/*
** Support functions
*/
void					skip_whitespaces(const char *s, int *i, float *fact);
float					ft_atof(const char *s);
unsigned int			ft_2d_str_count(const char **str);

/*
** Init
*/
t_scop					*init_scop();
int						init_sdl_gl(t_scop *scop);
void					init_open_gl_attributes();

/*
** Clean
*/
void					cleanup_sdl(t_scop *scop);

/*
** Parser
*/
void					obj_pars_main(t_scop *scop);
int						is_obj(t_scop *scop);
void					vertices_pars(t_scop *scop);
void					vertices_count(t_scop *scop);
void					vertices_allocate_mem(t_scop *scop);
void					vertices_write(t_scop *scop);
void					indices_pars(t_scop *scop);
void					indices_count(t_scop *scop);
void					indices_allocate_mem(t_scop *scop);
void					indices_write(t_scop *scop);
void					indices_write_three(t_scop *scop, char **s_values);
void					indices_write_four(t_scop *scop, char **s_values);

/*
** Main program loop
*/
void					main_loop(t_scop *scop);
int						key_down(t_scop *scop);

/*
** Shaders
*/
void					load_shaders(t_scop *scop);
char					*parser_shader(const char *file_path);
void					build_shaders(t_scop *scop);
void					print_error(unsigned int shader, char *log);
void					compile_shader(int shader);
void					remove_trailing_comment(char *shader_source);

/*
** Render
*/
void					main_render(t_scop *scop);

/*
** Vertext data
*/
void					main_vertex_data(t_scop *scop);
void					set_up_vertex_data(t_scop *scop);

/*
** Vector math
*/
t_vec3					vec3_set(float x, float y, float z);
float					vec3_magnitude(t_vec3 v);
t_vec3					vec3_normalize(t_vec3 v);
t_vec3					vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3					vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3					vec3_cross(t_vec3 v1, t_vec3 v2);
float					vec3_dot(t_vec3 v1, t_vec3 v2);

/*
** Matrix
*/
void					main_matrix(t_scop *scop);
void					set_camera(t_scop *scop);
t_mat4					mat_build_view(t_vec3 eye, t_vec3 center, t_vec3 up);
t_mat4					set_view_help(t_vec3 x, t_vec3 y, t_vec3 z, t_vec3 e);
t_mat4					mat_build_persp(float f, float a, float n, float far);

#endif
