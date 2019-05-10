/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:56:01 by swarner           #+#    #+#             */
/*   Updated: 2019/04/25 16:56:02 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_fill_map(char *map, int field_n, int field)
{
	int i;

	i = 0;
	while (i < field_n)
		map[i++] = '.';
	i = 0;
	while (i < field_n)
	{
		if (((i + 1) % (ft_sqrt(field) + 1) == 0))
			map[i] = '\n';
		i++;
	}
	return (map);
}

char			*ft_field_for_tetri(int count, int step)
{
	int		i;
	int		field;
	int		field_n;
	char	*tetri_field;

	i = 0;
	if (step == 0)
		step = 1;
	else
		step = step * 2;
	while (ft_sqrt((count * step) * 4 + i) == 0)
		i++;
	field = ((count * step) * 4) + i;
	field_n = field + ft_sqrt(field);
	tetri_field = ft_strnew(field_n);
	return (ft_fill_map(tetri_field, field_n, field));
}

void			ft_change_coordinates(int *coo)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		if (coo[i] / 4 == 1)
			coo[i] += 1;
		if (coo[i] / 4 == 2)
			coo[i] += 2;
		if (coo[i] / 4 == 3)
			coo[i] += 3;
		i++;
	}
}
