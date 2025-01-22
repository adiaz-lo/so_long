/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:30:28 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/05/16 12:30:30 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l_new;

	l_new = (t_list *)malloc(sizeof(t_list));
	if (!l_new)
		return (NULL);
	l_new->content = content;
	l_new->next = NULL;
	return (l_new);
}
