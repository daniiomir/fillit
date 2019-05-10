/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:55:19 by swarner           #+#    #+#             */
/*   Updated: 2019/04/25 16:55:22 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		valid_tetri;
	char	*tetri_map;
	t_dlist	*val_list;

	if (argc == 2)
	{
		val_list = ft_dlist_new(NULL, 0);
		valid_tetri = ft_open_and_validation(argv[1], val_list);
		tetri_map = ft_field_for_tetri(valid_tetri, 0);
		//ft_putstr(ft_field_for_tetri(valid_tetri, 0));
		ft_solve(tetri_map, val_list, 0, ft_strlen(tetri_map));
		ft_putendl(tetri_map);
	}
	else
		ft_putendl("usage: ./fillit [file]");
}
