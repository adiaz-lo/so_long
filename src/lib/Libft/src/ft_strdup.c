/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:19:39 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/04/10 12:43:33 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char			*scpy;
	const size_t	len = ft_strlen(s) + 1;

	scpy = malloc(len);
	if (scpy)
		ft_strlcpy(scpy, s, len);
	else
		return (NULL);
	return (scpy);
}
