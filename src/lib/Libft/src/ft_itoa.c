/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:08:34 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/04/25 16:19:01 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	len;
	long	lonum;

	lonum = n;
	len = ft_intlen(lonum);
	string = malloc (len + 1);
	if (!string)
		return (NULL);
	string[len] = '\0';
	if (lonum < 0)
	{
		string[0] = '-';
		lonum = -lonum;
	}
	if (lonum == 0)
		string[0] = '0';
	while (lonum)
	{
		string[--len] = lonum % 10 + '0';
		lonum /= 10;
	}
	return (string);
}
