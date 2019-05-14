/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <gfoote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:55:19 by swarner           #+#    #+#             */
/*   Updated: 2019/05/14 15:45:21 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		i;
	int		step;
	int		valid_tetri;
	char	*tetri_map;
	t_dlist	*val_list;

	if (argc == 2)
	{
		i = 0;
		step = 0;
		val_list = ft_dlist_new(NULL, 0);
		valid_tetri = ft_open_and_validation(argv[1], &val_list);
		tetri_map = ft_field_for_tetri(valid_tetri, i, val_list);
		while (ft_solve(val_list, tetri_map, step) == 0)
		{
			i = ft_sqrt(ft_strlen(tetri_map));
			free(tetri_map);
			tetri_map = ft_field_for_tetri(valid_tetri, i, val_list);
		}
	}
	else
		ft_putendl("usage: ./fillit [file]");
}
