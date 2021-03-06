/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:23:49 by swarner           #+#    #+#             */
/*   Updated: 2019/05/14 15:12:59 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_add_tetri(char *tetri_map, t_dlist *current, int step)
{
	int		*coo;
	int		letter;
	int		map_len;

	map_len = ft_strlen(tetri_map);
	coo = (int *)(current->content);
	letter = current->content_size;
	while (tetri_map[step] != '\0' && tetri_map[step] != '.')
		step++;
	if (step + coo[3] - coo[0] < map_len &&
		tetri_map[step + coo[1] - coo[0]] == '.'
		&& tetri_map[step + coo[2] - coo[0]] == '.' &&
		tetri_map[step + coo[3] - coo[0]] == '.')
	{
		tetri_map[step] = letter;
		tetri_map[step + coo[1] - coo[0]] = letter;
		tetri_map[step + coo[2] - coo[0]] = letter;
		tetri_map[step + coo[3] - coo[0]] = letter;
		return (step);
	}
	return (tetri_map[step + 1] == '\0') ? -1 :
	(ft_add_tetri(tetri_map, current, step + 1));
}

int		ft_del_tetri(char *tetri_map, int letter)
{
	int		i;
	int		step;
	int		check;

	i = 0;
	check = 0;
	while (tetri_map[i])
	{
		if (tetri_map[i] == letter)
		{
			if (check == 0)
				step = i;
			check = 1;
			tetri_map[i] = '.';
		}
		i++;
	}
	return (step);
}

int		ft_solve(t_dlist *val_list, char *tetri_map, int step)
{
	t_dlist *current;

	current = val_list;
	while (current != NULL || (current->next == NULL && step != -1))
	{
		step = ft_add_tetri(tetri_map, current, step);
		if (current->prev == NULL && step == -1)
			break ;
		if (!current->next && step != -1)
			ft_putstr_exit(tetri_map, val_list);
		if (current->next && step != -1)
		{
			step = 0;
			current = current->next;
		}
		if (step == -1)
		{
			if (current->prev)
			{
				current = current->prev;
				step = ft_del_tetri(tetri_map, current->content_size) + 1;
			}
		}
	}
	return (0);
}
