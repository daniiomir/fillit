/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:57:14 by swarner           #+#    #+#             */
/*   Updated: 2019/04/21 21:57:16 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_tetri_to_coo(char *buffer)
{
	int		i;
	int		j;
	int		g;
	int		*coo;

	i = 0;
	j = 0;
	g = 0;
	coo = (int *)malloc(3);
	while (buffer[i] != '#')
		i++;
	while (buffer[i] != '\0')
	{
		i++;
		j++;
		if (buffer[i] == '#')
			coo[g++] = j;
	}
	free(buffer);
	return (coo);
}

void	ft_check_tetri(char *buffer)
{
	int		i;
	int		shapes;

	i = 0;
	shapes = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '#')
		{
			if (i > 0 && buffer[i - 1] == '#')
				shapes++;
			if (i < 19 && buffer[i + 1] == '#')
				shapes++;
			if (i >= 5 && buffer[i - 5] == '#')
				shapes++;
			if (i <= 14 && buffer[i + 5] == '#')
				shapes++;
		}
		i++;
	}
	if (shapes == 6 || shapes == 8)
		return ;
	ft_error();
}

int		ft_main_validation(t_dlist *val_list)
{
	int		count;
	t_dlist	*current;

	count = 0;
	current = val_list;
	while (current != NULL)
	{
		count++;
		if (current->next)
			ft_check_spaces(current->content);
		if (!current->next)
			ft_check_spaces_last(current->content);
		ft_count_and_check_symbols(current->content);
		ft_check_tetri(current->content);
		current->content = ft_tetri_to_coo(current->content);
		current = current->next;
	}
	if (count > 26)
		ft_error();
	return (count);
}

int		ft_open_and_validation(char *arg, t_dlist *val_list)
{
	int		fd;
	int		ret;
	int		step;
	char	buffer[23];

	step = 0;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		ft_error();
	while ((ret = read(fd, buffer, 21)))
	{
		buffer[21] = '\0';
		ft_addnode_dlist(&val_list, buffer, 'A' + step);
		step++;
	}
	if (ret < 0)
		ft_error();
	ft_dlisthead_del(&val_list);
	return (ft_main_validation(val_list));
}
