#include "scop.h"

void	print_error(unsigned int shader, char *log)
{
	glGetShaderInfoLog(shader, 512, NULL, log);
	perror(log);
}