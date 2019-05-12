/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:23:49 by swarner           #+#    #+#             */
/*   Updated: 2019/05/12 16:23:52 by swarner          ###   ########.fr       */
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
	if (step + coo[2] < map_len && tetri_map[step + coo[0]] == '.'
		&& tetri_map[step + coo[1]] == '.' && tetri_map[step + coo[2]] == '.')
	{
		tetri_map[step] = letter;
		tetri_map[step + coo[0]] = letter;
		tetri_map[step + coo[1]] = letter;
		tetri_map[step + coo[2]] = letter;
		return (step);
	}
	if (tetri_map[step + 1] == '\0')
			return (-1);
	else
			return (ft_add_tetri(tetri_map, current, step + 1));
	return (0);
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
	while (current != NULL)
	{
		step = ft_add_tetri(tetri_map, current, step);
		if (current->prev == NULL && step == -1)
            break ;
		if (current->next && step != -1)
		    current = current->next;
		if (step == -1)
		{
		    if (current->prev)
		    {
                current = current->prev;
		        step = ft_del_tetri(tetri_map, current->content_size) + 1;
		    }
		}
	}
	if (step != -1)
	    return (1);
	return (0);
}
