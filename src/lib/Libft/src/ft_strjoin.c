/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:40:10 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/10/21 17:41:20 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	size_t		s1l;
	size_t		s2l;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	str = malloc(s1l + s2l + 1);
	if (!str)
		return (NULL);
	if (str)
	{
		ft_memcpy(str, s1, s1l);
		ft_memcpy(str + s1l, s2, s2l);
		str [s1l + s2l] = '\0';
	}
	return (str);
}
