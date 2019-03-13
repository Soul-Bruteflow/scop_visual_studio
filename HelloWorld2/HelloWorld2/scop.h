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
** Main data structure
*/
typedef struct			s_scop
{
	SDL_Window			*sld_win;
	char				*obj_file_name;
	unsigned int		vetrex_count;
	float				*vertices;
}						t_scop;

/*
** Init
*/
t_scop					*init_scop();

/*
** Parser
*/
void					obj_pars_main(t_scop *scop);
void					count_vertices(t_scop *scop);
void					allocate_vetrex_mem(t_scop *scop);
void					write_vertices(t_scop *scop);

#endif