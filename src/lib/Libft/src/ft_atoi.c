/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:28:24 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/04/25 14:42:47 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || \
		c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *string)
{
	int		sign;
	int		number;

	sign = 1;
	while (ft_isspace(*string))
		string++;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	else if (*string == '+')
	{
		string++;
	}
	number = 0;
	while (ft_isdigit(*string))
	{
		number = 10 * number + (*string - '0');
		string++;
	}
	return (sign * number);
}
