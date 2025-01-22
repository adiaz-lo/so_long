/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:00:54 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/04/28 11:48:13 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *string, int c)
{
	char	*str;
	char	c_char;

	str = (char *)string;
	c_char = (char)c;
	while (*str)
	{
		if (c_char == *str)
			return (str);
		str++;
	}
	if (c_char == '\0')
		return (str);
	return (0);
}
