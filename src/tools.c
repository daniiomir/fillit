/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:04:14 by swarner           #+#    #+#             */
/*   Updated: 2019/05/01 18:04:21 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("Error");
	exit(1);
}

void	ft_check_spaces(char *buffer)
{
	if (buffer[4] == '\n' && buffer[9] == '\n' \
		&& buffer[14] == '\n' && buffer[19] == '\n' \
		&& buffer[20] == '\n')
		return ;
	ft_error();
}

void	ft_check_spaces_last(char *buffer)
{
	if (buffer[4] == '\n' && buffer[9] == '\n' \
		&& buffer[14] == '\n' && buffer[19] == '\n')
		return ;
	ft_error();
}
