/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:54:13 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/04/24 16:12:10 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t eltsize)
{
	void	*value;

	value = malloc(count * eltsize);
	if (value)
		ft_bzero(value, count * eltsize);
	else
		return (NULL);
	return (value);
}
