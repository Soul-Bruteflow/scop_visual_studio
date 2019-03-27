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

int					load_tga(t_scop *scop, int n)
{
	FILE			*file_ptr;
	unsigned char	uchar_bad;
	short int		sint_bad;
	int				color_mode;
	unsigned char	color_swap;

	// Open the TGA file.
	file_ptr = fopen(scop->t[n].filename, "rb");
	if (file_ptr == NULL)
	{
		return (0);
	}

	// Read the two first bytes we don't need.
	fread(&uchar_bad, sizeof(unsigned char), 1, file_ptr);
	fread(&uchar_bad, sizeof(unsigned char), 1, file_ptr);

	// Which type of image gets stored in imageTypeCode.
	fread(&scop->t[n].tga_type_code, sizeof(unsigned char), 1, file_ptr);

	// For our purposes, the type code should be 2 (uncompressed RGB image)
	// or 3 (uncompressed black-and-white images).
	if (scop->t[n].tga_type_code != 2 && scop->t[n].tga_type_code != 3)
	{
		fclose(file_ptr);
		return (0);
	}

	// Read 13 bytes of data we don't need.
	fread(&sint_bad, sizeof(short int), 1, file_ptr);
	fread(&sint_bad, sizeof(short int), 1, file_ptr);
	fread(&uchar_bad, sizeof(unsigned char), 1, file_ptr);
	fread(&sint_bad, sizeof(short int), 1, file_ptr);
	fread(&sint_bad, sizeof(short int), 1, file_ptr);

	// Read the image's width and height.
	fread(&scop->t[n].tga_width, sizeof(short int), 1, file_ptr);
	fread(&scop->t[n].tga_height, sizeof(short int), 1, file_ptr);

	// Read the bit depth.
	fread(&scop->t[n].tga_bit_count, sizeof(unsigned char), 1, file_ptr);

	// Read one byte of data we don't need.
	fread(&uchar_bad, sizeof(unsigned char), 1, file_ptr);

	// Color mode -> 3 = BGR, 4 = BGRA.
	color_mode = scop->t[n].tga_bit_count / 8;
	scop->t[n].tga_image_size = scop->t[n].tga_width * scop->t[n].tga_height * color_mode;

	// Allocate memory for the image data.
	scop->t[n].tga_image_data = (unsigned char*)malloc(sizeof(unsigned char) * scop->t[n].tga_image_size);

	// Read the image data.
	fread(scop->t[n].tga_image_data, sizeof(unsigned char), scop->t[n].tga_image_size, file_ptr);

	// Change from BGR to RGB so OpenGL can read the image data.
	scop->t[n].i = 0;
	while (scop->t[n].i < scop->t[n].tga_image_size)
	{
		color_swap = scop->t[n].tga_image_data[scop->t[n].i];
		scop->t[n].tga_image_data[scop->t[n].i] = scop->t[n].tga_image_data[scop->t[n].i + 2];
		scop->t[n].tga_image_data[scop->t[n].i + 2] = color_swap;
		scop->t[n].i += color_mode;
	}
	fclose(file_ptr);
	return (1);
}
