#include "scop.h"

//void	read_header(t_scop *scop)
//{
//	FILE	*file;
//
//	if ((file = fopen(BMP_PATH_1, "r")) == NULL)
//		perror("Failed to open BMP :(");
//	fseek(file, 18, SEEK_SET);
//	fread(&scop->tex_w, 4, 1, file);
//	fread(&scop->tex_h, 4, 1, file);
//	fseek(file, 2, SEEK_CUR);
//	fread(&scop->tex_bpp, 2, 1, file);
//	fclose(file);
//	printf("scop->tex_opp: %d\n", scop->tex_opp);
//	scop->tex_opp = scop->tex_bpp / 8;
//	scop->tex_sl = scop->tex_w * scop->tex_opp;
//	scop->tex_w < 0 ? scop->tex_w = -scop->tex_w : 0;
//	scop->tex_h < 0 ? scop->tex_h = -scop->tex_h : 0;
//	scop->tex_size = scop->tex_sl * scop->tex_h;
//	printf("scop->tex_opp: %d\n", scop->tex_opp);
//	printf("scop->tex_sl: %d\n", scop->tex_sl);
//	printf("scop->tex_w: %d\n", scop->tex_w);
//	printf("scop->tex_h: %d\n", scop->tex_h);
//	printf("scop->tex_size: %d\n", scop->tex_size);
//}
//
//void	get_image(t_scop *scop, char *buffer, int i)
//{
//	int	h;
//	int	j;
//
//	h = 0;
//	scop->tex_img = malloc(sizeof(unsigned char) * scop->tex_size * 2);
//	while (i >= 0)
//	{
//		i -= scop->tex_sl;
//		j = 0;
//		while (j < scop->tex_sl)
//		{
//			scop->tex_img[h + j + 0] = (unsigned char)buffer[i + j + 2];
//			scop->tex_img[h + j + 1] = (unsigned char)buffer[i + j + 1];
//			scop->tex_img[h + j + 2] = (unsigned char)buffer[i + j + 0];
//			j += 3;
//		}
//		h += scop->tex_sl;
//	}
//}
//
//void	load_bmp(t_scop *scop)
//{
//	int		fd;
//	int		i;
//	char	*buffer;
//
//	read_header(scop);
//	buffer = (char*)malloc(sizeof(char) * scop->tex_size + 1);
//	if ((fd = open(BMP_PATH_1, O_RDWR)) == -1)
//		perror("Failed to open BMP :(");
//	lseek(fd, 54, SEEK_SET);
//	i = read(fd, buffer, scop->tex_size);
//	get_image(scop, buffer, i);
//	ft_strdel((char**)&buffer);
//	close(fd);
//}

//int			load_bmp(t_scop *scop)
//{
//	FILE	*file;
//
//	file = fopen(BMP_PATH_1, "rb");
//	if (!file)
//	{
//		perror("Image could not be opened\n");
//		return (-1);
//	}
//	if (fread(scop->bmp_header, 1, 54, file) != 54)
//	{
//		perror("Not a correct BMP file\n");
//		return (-1);
//	}
//	if (scop->bmp_header[0] != 'B' || scop->bmp_header[1] != 'M')
//	{
//		perror("Not a correct BMP file\n");
//		return (-1);
//	}
//	scop->bmp_data_pos = *(int*)&(scop->bmp_header[0x0A]);
//	scop->bmp_image_size = *(int*)&(scop->bmp_header[0x22]);
//	scop->bmp_width = *(int*)&(scop->bmp_header[0x12]);
//	scop->bmp_height = *(int*)&(scop->bmp_header[0x16]);
//	if (scop->bmp_image_size == 0)
//		scop->bmp_image_size = scop->bmp_width * scop->bmp_height * 3;
//	if (scop->bmp_data_pos == 0)
//		scop->bmp_data_pos = 54;
//	scop->bmp_data = (unsigned char)malloc(sizeof(unsigned char) * scop->bmp_image_size);
//	fread(scop->bmp_data, 1, scop->bmp_image_size, file);
//	fclose(file);
//	return (1);
//}

int					load_tga(char *filename, t_scop *scop)
{
	FILE			*file_ptr;
	unsigned char	uchar_bad;
	short int		sint_bad;
	int				color_mode;
	unsigned char	color_swap;

	// Open the TGA file.
	file_ptr = fopen(filename, "rb");
	if (file_ptr == NULL)
	{
		return (0);
	}

	// Read the two first bytes we don't need.
	fread(&uchar_bad, sizeof(unsigned char), 1, file_ptr);
	fread(&uchar_bad, sizeof(unsigned char), 1, file_ptr);

	// Which type of image gets stored in imageTypeCode.
	fread(&scop->tga_type_code, sizeof(unsigned char), 1, file_ptr);

	// For our purposes, the type code should be 2 (uncompressed RGB image)
	// or 3 (uncompressed black-and-white images).
	if (scop->tga_type_code != 2 && scop->tga_type_code != 3)
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
	fread(&scop->tga_width, sizeof(short int), 1, file_ptr);
	fread(&scop->tga_height, sizeof(short int), 1, file_ptr);

	// Read the bit depth.
	fread(&scop->tga_bit_count, sizeof(unsigned char), 1, file_ptr);

	// Read one byte of data we don't need.
	fread(&uchar_bad, sizeof(unsigned char), 1, file_ptr);

	// Color mode -> 3 = BGR, 4 = BGRA.
	color_mode = scop->tga_bit_count / 8;
	scop->tga_image_size = scop->tga_width * scop->tga_height * color_mode;

	// Allocate memory for the image data.
	scop->tga_image_data = (unsigned char*)malloc(sizeof(unsigned char) * scop->tga_image_size);

	// Read the image data.
	fread(scop->tga_image_data, sizeof(unsigned char), scop->tga_image_size, file_ptr);

	// Change from BGR to RGB so OpenGL can read the image data.
	scop->i = 0;
	while (scop->i < scop->tga_image_size)
	{
		color_swap = scop->tga_image_data[scop->i];
		scop->tga_image_data[scop->i] = scop->tga_image_data[scop->i + 2];
		scop->tga_image_data[scop->i + 2] = color_swap;
		scop->i += color_mode;
	}
	fclose(file_ptr);
	return (1);
}
