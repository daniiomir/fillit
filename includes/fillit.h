/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:50:36 by swarner           #+#    #+#             */
/*   Updated: 2019/04/21 21:50:38 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

int		ft_main_validation(t_dlist *val_list);
void	ft_check_spaces(char	*buffer);
void	ft_check_spaces_last(char	*buffer);
void	ft_count_and_check_symbols(char *buffer);
int		ft_open_and_validation(char *arg, t_dlist **val_list);
void	ft_error(void);
int		ft_sqrt(int nb);
void	ft_check_tetri(char *buffer);
int		*ft_tetri_to_coo(char *buffer);
char	*ft_field_for_tetri(int	count, int step, t_dlist *val_list);
void	ft_change_coordinates(t_dlist *val_list, int cur_size, int prev_size);
int		ft_add_tetri(char *tetri_map, t_dlist *current, int step);
int		ft_del_tetri(char *tetri_map, int letter);
int		ft_solve(t_dlist *val_list, char *tetri_map, int step);
void	ft_putstr_exit(const char *s);

#endif
