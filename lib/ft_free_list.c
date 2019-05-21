/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:54:50 by swarner           #+#    #+#             */
/*   Updated: 2019/05/21 14:54:51 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_list *list)
{
	t_list		*current;

	current = list;
	while (current != NULL)
	{
		free(current->content);
		current = current->next;
	}
	free(list);
}
