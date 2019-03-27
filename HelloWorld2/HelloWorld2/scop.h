/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:56 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:50:56 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
** External libs
*/
# include				<math.h>
# include				<time.h>
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
# define BUFF_COUNT		3
# define MOD_COUNT		4
# define TEX_COUNT		10
# define WINNAME		"scop"
# define VERT_PATH		"shader_vertex.glsl"
# define FRAG_PATH		"shader_fragment.glsl"
# define TGA_PATH_1		"texture_1.tga"
# define TGA_PATH_2		"texture_2.tga"
# define TGA_PATH_3		"texture_3.tga"
# define TGA_PATH_4		"texture_4.tga"
# define TGA_PATH_5		"texture_5.tga"
# define TGA_PATH_6		"texture_6.tga"
# define TGA_PATH_7		"texture_7.tga"
# define TGA_PATH_8		"texture_8.tga"
# define TGA_PATH_9		"texture_9.tga"
# define TGA_PATH_10	"texture_10.tga"
# define TGA_GL_1		"tex_1"
# define TGA_GL_2		"tex_2"
# define TGA_GL_3		"tex_3"
# define TGA_GL_4		"tex_4"
# define TGA_GL_5		"tex_5"
# define TGA_GL_6		"tex_6"
# define TGA_GL_7		"tex_7"
# define TGA_GL_8		"tex_8"
# define TGA_GL_9		"tex_9"
# define TGA_GL_10		"tex_10"
# define PROFILE_CORE	0x0001

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

typedef struct			s_tex
{
	unsigned char		tga_type_code;
	short int			tga_width;
	short int			tga_height;
	unsigned char		tga_bit_count;
	unsigned char		*tga_image_data;
	long				tga_image_size;
	unsigned int		i;
	char				*filename;
	char				*gl_name;
	int					gl_id;
}						t_tex;

/*
** Main data structure
*/
typedef struct			s_scop
{
	SDL_Window			*main_window;
	SDL_GLContext		main_context;
	SDL_Event			event;
	char				*obj_file_name;
	unsigned int		vert_num;
	unsigned int		indic_num;
	float				*verts;
	float				*colors;
	unsigned int		*indic;
	int					i;
	int					vertex_shader;
	int					fragment_shader;
	int					shdr_prog;
	char				*vertex_shdr_src;
	char				*fragment_shdr_src;
	unsigned int		vbo;
	unsigned int		ebo;
	unsigned int		vao;
	unsigned int		buffers[BUFF_COUNT];
	unsigned int		buffers_idx[BUFF_COUNT - 1];
	t_vec3				up;
	t_vec3				eye;
	t_vec3				center;
	t_mat4				view;
	int					view_id;
	t_mat4				proj;
	int					proj_id;
	float				fov;
	float				near;
	float				far;
	float				asp;
	float				scale_factor;
	t_mat4				model;
	int					model_id;
	int					texture_id;
	t_vec3				move_fac;
	t_mat4				scale;
	t_mat4				translate;
	int					scale_id;
	int					trans_id;
	t_mat4				rotate_x;
	t_mat4				rotate_y;
	t_mat4				rotate_z;
	t_mat4				rotate_a;
	int					rotate_a_id;
	int					rotate_x_id;
	int					rotate_y_id;
	int					rotate_z_id;
	float				rot_x_fac;
	float				rot_y_fac;
	float				rot_z_fac;
	float				rot_a_fac;
	t_vec3				min;
	t_vec3				max;
	t_vec3				object_center;
	t_vec3				object_back;
	t_mat4				trans_cent;
	t_mat4				trans_back;
	int					trans_cent_id;
	int					trans_back_id;
	int					enable_rotate;
	double				time;
	double				old_time;
	double				delta;
	int					copy_auto;
	int					copy_auto2;
	int					is_draw_lines;
	short				color_mode_1;
	short				color_mode_2;
	short				color_mode_3;
	short				color_mode_4;
	short				color_mode_5;
	short				color_mode_6;
	short				color_mode_7;
	int					mods_id_1;
	int					mods_id_2;
	int					mods_id_2_1;
	int					mods_id_3;
	int					mods_id_3_1;
	int					mods_id_4;
	int					mods_id_4_1;
	int					mods_id_5;
	int					mods_id_5_1;
	int					mods_id_6;
	int					mods_id_6_1;
	int					mods_id_7;
	int					mods_id_7_1;
	t_tex				t[TEX_COUNT];
	int					cur_tex_num;
	t_vec3				bgrd_col;
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
int						obj_pars_main(t_scop *scop);
int						is_obj(t_scop *scop);
int						read_wtire_v_f(t_scop *scop);
int						vertices_write(t_scop *scop, int cap, char *line);
int						indices_write(t_scop *scop, int cap2, char *line);
void					indices_write_three(t_scop *scop, char **s_values);
void					indices_write_four(t_scop *scop, char **s_values);
void					find_min_max(t_scop *scop);

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
void					transfer_matrices_to_gpu(t_scop *scop);
void					transfer_key_mods_to_gpu(t_scop *scop);
void					transfer_key_mods_to_gpu2(t_scop *scop);

/*
** Buffers
*/
void					create_gl_buffers(t_scop *scop);
void					create_index_buffer(t_scop *scop);
void					create_vertices_buffer(t_scop *scop);
void					create_colors_buffer(t_scop *scop);

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
t_mat4					mat_set_identity();
void					main_matrix(t_scop *scop);
void					set_view(t_scop *scop);
void					set_projection(t_scop *scop);
t_mat4					mat_build_view(t_vec3 eye, t_vec3 center, t_vec3 up);
t_mat4					set_view_help(t_vec3 x, t_vec3 y, t_vec3 z, t_vec3 e);
t_mat4					mat_build_proj(float f, float a, float n, float far);
t_mat4					mat_init(float val);
void					set_model_mats(t_scop *scop);
t_mat4					mat_scale(float f);
t_mat4					mat_translate(t_vec3 v);
t_mat4					mat_rotate(float angle, t_vec3 axis);

/*
** Key function | scale
*/
void					init_key(t_scop *scop);
void					scale_mesh(t_scop *scop);
void					translate_mesh(t_scop *scop);
float					translate_move(float base_value, int flag, double delta);
t_mat4					mat_set_rotate(float c, float s, t_vec3 axis);
void					rotate_x(t_scop *scop);
void					rotate_y(t_scop *scop);
void					rotate_z(t_scop *scop);
void					auto_rotate(t_scop *scop);
void					togle_auto_rotate(t_scop *scop);
void					togle_draw_lines(t_scop *scop);
void					togle_color_mod_1(t_scop *scop);
void					togle_color_mod_2(t_scop *scop);
void					togle_color_mod_3(t_scop *scop);
void					togle_color_mod_4(t_scop *scop);
void					togle_color_mod_5(t_scop *scop);
void					togle_color_mod_6(t_scop *scop);
void					togle_color_mod_7(t_scop *scop);
void					togle_color_refresh(t_scop *scop);
void					change_background_color(t_scop *scop);
void					move_camera(t_scop *scop);
void					move_camera_z(t_scop *scop);
void					move_camera_x(t_scop *scop);
void					move_camera_y(t_scop *scop);
void					toggle(t_scop *scop);

/*
** Colors
*/
void					main_colors(t_scop *scop);
void					colors_allocate_mem(t_scop *scop);
void					generate_random_colors(t_scop *scop);

/*
** Load tga
*/
int						load_tga(t_scop *scop, int n);
void					send_texture_to_opengl(t_scop *scop, int n);
int						load_all_tga(t_scop *scop);
void					generate_file_names(t_scop *scop);
void					send_all_textures(t_scop *scop);

#endif