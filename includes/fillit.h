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

void	ft_common_check_tetri(t_list *val_list);
void	ft_check_spaces(char	*buffer);
void	ft_check_spaces_last(char	*buffer);
void	ft_open(char *arg);
void	ft_error(void);

#endif