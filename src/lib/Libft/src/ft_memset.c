/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:18:32 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/04/28 11:43:17 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *block, int c, size_t size)
{
	char	temp_c;
	char	*c_block;
	size_t	i;

	temp_c = (unsigned char) c;
	c_block = (char *) block;
	if (size <= 0)
		return (block);
	i = 0;
	while (i < size)
	{
		c_block[i] = temp_c;
		i++;
	}
	return (block);
}
