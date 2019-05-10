/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:54:44 by swarner           #+#    #+#             */
/*   Updated: 2019/05/10 15:54:46 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_add_tetri(char *map, t_dlist *current, int step, int map_len)
{
	int		i;
	int		*a;
	int		letter;

	i = step;
	letter = current->content_size;
	while (map[i] != '.')
		i++;
	a = current->content;
	if ((i + a[0] < map_len) && (i + a[1] < map_len)
		&& (i + a[2] < map_len) && (map[i + a[0]] == '.')
		&& (map[i + a[1]] == '.') && map[i + a[2] == '.'])
	{
		map[i] = letter;
		map[i + a[0]] = letter;
		map[i + a[1]] = letter;
		map[i + a[2]] = letter;
		return (i);
	}
	else
	{
		if (map[i + 1] == '\0')
			return (-1);
		else
			return (ft_add_tetri(map, current, i + 1, map_len));
	}
	return (-1);
}

int		ft_del_tetri(char *map, int letter)
{
	int			pos;
	int			i;
	int			check;

	i = 0;
	check = 0;
	while (map[i])
	{
		if (map[i] == letter)
		{
			if (check == 0)
				pos = i;
			check = 1;
			map[i] = '.';
		}
		i++;
	}
	return (pos);
}

int		ft_solve(char *tetri_map, t_dlist *current, int step, int map_len)
{
	while (current)
	{
		step = ft_add_tetri(tetri_map, current, step, map_len);
		if (step != -1)
		{
			if (current->next)
				current = current->next;
			else
				return (1);
		}
		else
		{
			if (current->prev)
			{
				current = current->prev;
				step = (ft_del_tetri(tetri_map, current->content_size) + 1);
			}
			else
			{
				tetri_map = ft_field_for_tetri(map_len, 1); //почистить map прежде
				return (ft_solve(tetri_map, current, 0, map_len));
			}
		}
	}
	return (0);
}