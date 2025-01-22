/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:19:02 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/04/21 13:19:03 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = (number * size);
	str = (void *)malloc(number * size);
	if (!str)
		return (NULL);
	while (j--)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	ptr = ft_calloc(sizeof(char), (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	i = -1;
	j = 0;
	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char)) + 1);
	if (!str)
		return (free(s1), s1 = NULL, free(s2), s2 = NULL, NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	s2 = NULL;
	return (str);
}
