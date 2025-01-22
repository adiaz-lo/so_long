/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:53:22 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/04/28 11:35:58 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *to, const void *from, size_t size)
{
	unsigned char	*c_from;
	unsigned char	*c_to;

	c_from = (unsigned char *)from;
	c_to = (unsigned char *)to;
	if (c_to == NULL && c_from == NULL)
		return (NULL);
	if (c_to < c_from)
		return (ft_memcpy(to, from, size));
	else
		while (size--)
			c_to[size] = c_from[size];
	return (to);
}
