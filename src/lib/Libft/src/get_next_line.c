/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:18:39 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/04/21 13:18:41 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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
	int		nl_pos;

	bytes_read = BUFFER_SIZE;
	nl_pos = find_nl_pos(text);
	while (nl_pos < 0 && bytes_read == BUFFER_SIZE)
	{
		nl_pos = find_nl_pos(text);
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
	int	nl_pos;

	nl_pos = find_nl_pos(*text);
	if (nl_pos >= 0)
	{
		line = process_line(line, text, nl_pos);
		if (!line)
			return (free(*text), *text = NULL, NULL);
	}
	else if (line == NULL && *text[0] != '\0')
	{
		line = ft_substr(*text, 0, ft_strlen(*text));
		if (!line)
			return (free(*text), *text = NULL, NULL);
		free(*text);
		*text = NULL;
	}
	else
		return (free(*text), *text = NULL, NULL);
	return (line);
}

char	*process_line(char *line, char **text, int nl_pos)
{
	char	*tmp_ptr;

	tmp_ptr = *text;
	line = ft_substr(*text, 0, nl_pos + 1);
	if (!line)
		return (NULL);
	*text = ft_substr(*text, nl_pos + 1, ft_strlen(*text) - nl_pos);
	if (!*text)
		return (free(line), free(tmp_ptr), NULL);
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
	static char	*text = NULL;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0))
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	line = NULL;
	text = read_lines(fd, text);
	if (!text)
		return (NULL);
	line = get_final_line(line, &text);
	if (!line)
		return (NULL);
	return (line);
}
