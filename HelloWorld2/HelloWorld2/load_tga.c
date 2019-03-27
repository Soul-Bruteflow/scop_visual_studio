/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tga.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:50:16 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 13:50:16 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int				load_all_tga(t_scop *scop)
{
	int i;

	i = 0;
	generate_file_names(scop);
	while (i < TEX_COUNT)
	{
		if (load_tga(scop, i) == -1)
			return (-1);
		i++;
	}
	return (1);
}

void				generate_file_names(t_scop *scop)
{
	scop->t[0].filename = TGA_PATH_1;
	scop->t[0].gl_name = TGA_GL_1;
	scop->t[1].filename = TGA_PATH_2;
	scop->t[1].gl_name = TGA_GL_2;
	scop->t[2].filename = TGA_PATH_3;
	scop->t[2].gl_name = TGA_GL_3;
	scop->t[3].filename = TGA_PATH_4;
	scop->t[3].gl_name = TGA_GL_4;
	scop->t[4].filename = TGA_PATH_5;
	scop->t[4].gl_name = TGA_GL_5;
	scop->t[5].filename = TGA_PATH_6;
	scop->t[5].gl_name = TGA_GL_6;
	scop->t[6].filename = TGA_PATH_7;
	scop->t[6].gl_name = TGA_GL_7;
	scop->t[7].filename = TGA_PATH_8;
	scop->t[7].gl_name = TGA_GL_8;
	scop->t[8].filename = TGA_PATH_9;
	scop->t[8].gl_name = TGA_GL_9;
	scop->t[9].filename = TGA_PATH_10;
	scop->t[9].gl_name = TGA_GL_10;
}

int					load_tga(t_scop *s, int n)
{
	FILE			*file_ptr;

	file_ptr = fopen(s->t[n].filename, "rb");
	if (file_ptr == NULL)
		return (0);
	fread(&s->uchar_bad, sizeof(unsigned char), 1, file_ptr);
	fread(&s->uchar_bad, sizeof(unsigned char), 1, file_ptr);
	fread(&s->t[n].tga_type_code, sizeof(unsigned char), 1, file_ptr);
	if (s->t[n].tga_type_code != 2 && s->t[n].tga_type_code != 3)
	{
		fclose(file_ptr);
		return (0);
	}
	calculate_tga_data(s, n, file_ptr);
	s->t[n].i = 0;
	while (s->t[n].i < s->t[n].img_sz)
	{
		s->color_swap = s->t[n].img_data[s->t[n].i];
		s->t[n].img_data[s->t[n].i] = s->t[n].img_data[s->t[n].i + 2];
		s->t[n].img_data[s->t[n].i + 2] = s->color_swap;
		s->t[n].i += s->color_mode;
	}
	fclose(file_ptr);
	return (1);
}

int					calculate_tga_data(t_scop *s, int n, FILE *file_ptr)
{
	fread(&s->sint_bad, sizeof(short int), 1, file_ptr);
	fread(&s->sint_bad, sizeof(short int), 1, file_ptr);
	fread(&s->uchar_bad, sizeof(unsigned char), 1, file_ptr);
	fread(&s->sint_bad, sizeof(short int), 1, file_ptr);
	fread(&s->sint_bad, sizeof(short int), 1, file_ptr);
	fread(&s->t[n].tga_width, sizeof(short int), 1, file_ptr);
	fread(&s->t[n].tga_height, sizeof(short int), 1, file_ptr);
	fread(&s->t[n].tga_bit_count, sizeof(unsigned char), 1, file_ptr);
	fread(&s->uchar_bad, sizeof(unsigned char), 1, file_ptr);
	s->color_mode = s->t[n].tga_bit_count / 8;
	s->t[n].img_sz = s->t[n].tga_width * s->t[n].tga_height * s->color_mode;
	s->t[n].img_data = (Uchar*)malloc(sizeof(Uchar) * s->t[n].img_sz);
	fread(s->t[n].img_data, sizeof(unsigned char), s->t[n].img_sz, file_ptr);
}