/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:19:27 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/04/21 13:19:27 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include "libft.h"

int		find_nl_pos(const char *s);

void	*ft_calloc(size_t number, size_t size);

/*char	*ft_substr(char *s, size_t start, size_t len);

char	*ft_strjoin(char *s1, char *s2);*/

char	*read_lines(int fd, char *text);

char	*get_next_line(int fd);

//size_t	ft_strlen(const char *str);

char	*get_final_line(char *line, char **text);

char	*process_line(char *line, char **text, int i);

#endif
