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

int		ft_sqrt(int nb)
{
	int digit;

	digit = 1;
	while (digit * digit < nb)
		digit++;
	if (digit * digit == nb)
		return (digit);
	return (0);
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

void	ft_count_and_check_symbols(char *buffer)
{
	int	i;
	int	count;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] != '.' && buffer[i] != '#' && buffer[i] != '\n')
			ft_error();
		i++;
	}
	i = 0;
	count = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		ft_error();
}
