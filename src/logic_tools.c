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

char			*ft_field_for_tetri(int count, int step, t_dlist *val_list)
{
	int		i;
	int		field;
	int		field_n;
	char	*tetri_field;

	i = 0;
	while (ft_sqrt((count + step) * 4 + i) == 0)
		i++;
	field = ((count + step) * 4) + i;
	field_n = field + ft_sqrt(field);
	tetri_field = ft_strnew(field_n);
	if (step > 1 && ft_sqrt(field) > 4)
		ft_change_coordinates(val_list, ft_sqrt(field) - 1);
	return (ft_fill_map(tetri_field, field_n, field));
}

void ft_change_coordinates(t_dlist *val_list, int str_size)
{
	int		i;
	int		*coo;
	t_dlist *current;

	i = 0;
	current = val_list;
	while (current->next != NULL)
	{
		coo = (int *)current->content;
		i = 0;
		while (i != 3)
		{
//		    coo[i] += coo[i] / str_size;
			if (coo[i] / str_size == 1)
				coo[i] += 1;
			else if (coo[i] / str_size == 2)
				coo[i] += 2;
			else if (coo[i] / str_size == 3)
				coo[i] += 3;
			i++;
		}
		current = current->next;
	}
    i = 0;
    coo = (int *)current->content;
    while (i != 3)
    {
//		    coo[i] += coo[i] / str_size;
        if (coo[i] / str_size == 1)
            coo[i] += 1;
        else if (coo[i] / str_size == 2)
            coo[i] += 2;
        else if (coo[i] / str_size == 3)
            coo[i] += 3;
        i++;
    }
}
