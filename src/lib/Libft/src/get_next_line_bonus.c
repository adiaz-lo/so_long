/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:18:56 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/04/21 13:18:56 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

int	find_nl_pos(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_lines(int fd, char *text)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		nl_loc;

	bytes_read = BUFFER_SIZE;
	nl_loc = find_nl_pos(text);
	while (nl_loc < 0 && bytes_read == BUFFER_SIZE)
	{
		nl_loc = find_nl_pos(text);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read > 0)
		{
			text = ft_strjoin(text, buffer);
			if (!text)
				return (NULL);
		}
		if (bytes_read == 0)
			return (text);
	}
	return (text);
}

char	*get_final_line(char *line, char **text)
{
	int	nl_loc;
	int	len;

	nl_loc = find_nl_pos(*text);
	len = ft_strlen(*text);
	if (nl_loc >= 0)
	{
		line = process_line(line, text, nl_loc);
		if (!line)
			return (free(*text), *text = NULL, NULL);
	}
	else if (line == NULL && *text[0] != '\0')
	{
		line = ft_substr(*text, 0, len);
		if (!line)
			return (free(*text), *text = NULL, NULL);
		free(*text);
		*text = NULL;
	}
	else
		return (free(*text), *text = NULL, NULL);
	return (line);
}

char	*process_line(char *line, char **text, int nl_loc)
{
	char	*tmp_ptr;
	int		len;

	tmp_ptr = *text;
	line = ft_substr(*text, 0, nl_loc + 1);
	if (!line)
		return (NULL);
	len = ft_strlen(*text);
	*text = ft_substr(*text, nl_loc + 1, len - nl_loc);
	if (!*text)
	{
		free(line);
		free(tmp_ptr);
		return (NULL);
	}
	if (*text[0] == '\0')
	{
		free(*text);
		*text = NULL;
	}
	free(tmp_ptr);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*text[1024];
	char		*line;

	if (fd < 0 || fd > 1024)
	{
		free(text[fd]);
		text[fd] = NULL;
		return (NULL);
	}
	if (read(fd, NULL, 0))
	{
		free(text[fd]);
		text[fd] = NULL;
		return (NULL);
	}
	line = NULL;
	text[fd] = read_lines(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	line = get_final_line(line, &text[fd]);
	if (!line)
		return (NULL);
	return (line);
}
