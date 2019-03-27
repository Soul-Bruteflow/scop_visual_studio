/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <thelarion@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:51:50 by mvlad             #+#    #+#             */
/*   Updated: 2019/03/27 15:51:50 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			indices_write(t_scop *scop, int cap2, char *line)
{

	char	**splited_values;
	int		element_count;

	splited_values = ft_strsplit(&line[2], ' ');
	element_count = ft_2d_str_count(splited_values);
	if (element_count == 4)
		indices_write_four(scop, splited_values);
	else
		indices_write_three(scop, splited_values);
	free(splited_values);
	if (scop->indic_num == cap2)
	{
		cap2 *= 2;
		scop->indic = (Uint32*)realloc(scop->indic, cap2 * sizeof(Uint32));
	}
	return (cap2);
}

void		indices_write_three(t_scop *scop, char	**splited_values)
{
	scop->indic[scop->indic_num + 0] = (ft_atoi(splited_values[0]) - 1);
	scop->indic[scop->indic_num + 1] = (ft_atoi(splited_values[1]) - 1);
	scop->indic[scop->indic_num + 2] = (ft_atoi(splited_values[2]) - 1);
	scop->indic_num += 3;
}

void		indices_write_four(t_scop *scop, char	**splited_values)
{
	scop->indic[scop->indic_num + 0] = (ft_atoi(splited_values[0]) - 1);
	scop->indic[scop->indic_num + 1] = (ft_atoi(splited_values[1]) - 1);
	scop->indic[scop->indic_num + 2] = (ft_atoi(splited_values[2]) - 1);
	scop->indic[scop->indic_num + 3] = (ft_atoi(splited_values[0]) - 1);
	scop->indic[scop->indic_num + 4] = (ft_atoi(splited_values[2]) - 1);
	scop->indic[scop->indic_num + 5] = (ft_atoi(splited_values[3]) - 1);
	scop->indic_num += 6;
}