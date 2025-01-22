/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:13:41 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/09/14 11:13:42 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa_base(unsigned long nb, char *base)
{
	char			*hex;
	unsigned long	nbr;
	unsigned long	len;

	len = 0;
	nbr = nb;
	while (nb)
	{
		len++;
		nb /= 16;
	}
	if (nbr == 0)
		len++;
	hex = malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (nbr != 0 || len)
	{
		hex[--len] = base[nbr % 16];
		nbr /= 16;
	}
	return (hex);
}
