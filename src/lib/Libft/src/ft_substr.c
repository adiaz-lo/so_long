/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:25:20 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/04/28 10:53:01 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const size_t	sl = ft_strlen(s);
	const size_t	slfs = sl - start;
	char			*str;

	if (!s)
		return (NULL);
	if (len == 0 || start >= sl)
		return (ft_calloc(1, 1));
	if (slfs <= len)
		len = slfs;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
