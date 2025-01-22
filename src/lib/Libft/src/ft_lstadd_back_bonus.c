/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:37:59 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/05/16 11:40:38 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*l_last;

	if (!*lst)
		*lst = new_node;
	else
	{
		l_last = ft_lstlast(*lst);
		l_last->next = new_node;
	}
}
