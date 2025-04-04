/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:25:05 by event             #+#    #+#             */
/*   Updated: 2025/04/04 19:25:08 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void throw_error(char *string_error) {
  perror(string_error); // ¿Cambiar por ft_printf para evitar el errno en el
                        // output?
  exit(1);
}
