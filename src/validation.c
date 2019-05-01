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

void	ft_main_validation(t_list *val_list)
{
	int		count;
	t_list	*current;

	count = 0;
	current = val_list;
	while (current != NULL)
	{
		count++;
		ft_putstr(current->content);
		if (current->next)
			ft_check_spaces(current->content);
		if (!current->next)
			ft_check_spaces_last(current->content);
		ft_check_symbols(current->content);
		ft_count_hashtags(current->content);
		ft_check_tetri(current->content);
		current = current->next;
	}
	if (count > 26)
		ft_error();
}

void	ft_open_and_validation(char *arg, t_list *val_list)
{
	int		fd;
	int		ret;
	int		count;
	char	buffer[23];

	count = 0;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		ft_error();
	while ((ret = read(fd, buffer, 21)))
	{
		buffer[21] = '\0';
		ft_addnode(&val_list, buffer);
	}
	if (ret < 0)
		ft_error();
	ft_lsthead_del(&val_list);
	ft_main_validation(val_list);
}
