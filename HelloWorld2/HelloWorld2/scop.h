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
	unsigned int		vertices_count;
	unsigned int		indices_count;
	float				*vertices;
	unsigned int		*indices;
	int					i;
}						t_scop;

/*
** Support functions
*/
void					skip_whitespaces(const char *s, int *i, float *fact);
float					ft_atof(const char *s);

/*
** Init
*/
t_scop					*init_scop();

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

#endif
