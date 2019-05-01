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

void	ft_common_check_tetri(t_list *val_list)
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
		current = current->next;
	}
	if (count > 26)
		ft_error();
}

void	ft_check_tetri(char *tetri)
{
	
}

void	ft_open(char *arg)
{
	int		fd;
	int		ret;
	int		count;
	t_list	*val_list;
	char	buffer[23];

	count = 0;
	fd = open(arg, O_RDONLY);
	val_list = ft_lstnew(NULL, 0);
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
	ft_common_check_tetri(val_list);
}
