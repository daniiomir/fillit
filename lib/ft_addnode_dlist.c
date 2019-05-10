/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnode_dlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:07:55 by swarner           #+#    #+#             */
/*   Updated: 2019/05/10 15:07:57 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addnode_dlist(t_dlist **val_list, char *buffer, int size)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	new->content = ft_strdup(buffer);
	new->content_size = size;
	new->next = NULL;
	ft_dlistadd_end(val_list, new);
	ft_strclr(buffer);
}
