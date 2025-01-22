/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:54:19 by adiaz-lo          #+#    #+#             */
/*   Updated: 2023/04/24 16:13:32 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isgraph(int c)
{
	if (c > ' ' && c < 127)
		return (1);
	else
		return (0);
}

int	ft_isprint(int c)
{
	if (ft_isgraph(c) || c == ' ')
		return (1);
	else
		return (0);
}
