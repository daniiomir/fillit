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

static void    ft_strset(char *field, int c, int size)
{
    int i;

    i = 0;
    while (i < size)
        field[i++] = c;
}

char	        *ft_field_for_tetri(int	count)
{
	int		i;
	int		field;
	int		field_n;
	char	*tetri_field;

	i = 0;
	while (ft_sqrt(count * 4 + i) == 0)
		i++;
	field = (count * 4) + i;
	field_n = field + ft_sqrt(field);
	tetri_field = ft_strnew(field_n);
	ft_strset(tetri_field, '.', field_n);
	i = 0;
	while (i < field_n)
	{
	    if (((i + 1) % (ft_sqrt(field) + 1) == 0))
    		tetri_field[i] = '\n';
		i++;
	}
	return (tetri_field);
}
