/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:56:01 by swarner           #+#    #+#             */
/*   Updated: 2019/05/14 15:12:49 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putstr_exit(const char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	exit(1);
}

static char	*ft_fill_map(char *map, int field_n, int field)
{
	int		i;

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

static int	ft_check_count(t_dlist *val_list, int count)
{
	int		*coo;
	t_dlist	*listik;

	listik = val_list;
	while (listik)
	{
		coo = (int *)listik->content;
		if ((coo[1] == 1 && coo[2] == 2 && coo[3] == 3)
		|| (coo[1] == 5 && coo[2] == 10 && coo[3] == 15))
			return (16);
		else if (coo[0] == 0 && coo[1] == 1 && coo[2] == 5
		&& coo[3] == 6 && count == 1)
			return (4);
		listik = listik->next;
	}
	return (9);
}

char		*ft_field_for_tetri(int count, int step, t_dlist *val_list)
{
	int		field;
	int		field_n;
	char	*tetri_field;

	if (count < 3 && step == 0)
		field = ft_check_count(val_list, count);
	else
	{
		if (step == 0)
			field = ft_sqrt(count * 4) * ft_sqrt(count * 4);
		else
			field = (step * step);
	}
	field_n = field + ft_sqrt(field);
	tetri_field = ft_strnew(field_n);
	if (step == 0)
		ft_change_coordinates(val_list, ft_sqrt(field), 4);
	else
		ft_change_coordinates(val_list, ft_sqrt(field), ft_sqrt(field) - 1);
	return (ft_fill_map(tetri_field, field_n, field));
}

void		ft_change_coordinates(t_dlist *val_list, int cur, int prev)
{
	int		i;
	int		*coo;
	t_dlist *current;
	int		diff;
	int		del;

	current = val_list;
	diff = cur - prev;
	del = (diff > 0 && diff < 2) ? cur : prev;
	while (current != NULL)
	{
		coo = (int *)current->content;
		i = 0;
		while (i != 4)
		{
			if (coo[i] / del == 1)
				coo[i] += diff;
			else if (coo[i] / del == 2)
				coo[i] += 2 * diff;
			else if (coo[i] / del == 3)
				coo[i] += 3 * diff;
			i++;
		}
		current = current->next;
	}
}
