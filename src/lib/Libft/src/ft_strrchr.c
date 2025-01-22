/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:57:29 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/05/01 17:37:19 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *string, int c)
{
	char	c_char;
	size_t	len;

	c_char = (char)c;
	len = ft_strlen(string);
	if (c_char == '\0')
		return ((char *)string + len);
	while (len > 0)
	{
		if (c_char == string[len - 1])
			return ((char *)string + len - 1);
		len--;
	}
	return (0);
}
