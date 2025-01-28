/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:32:22 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/28 12:11:58 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_remains(char *line)
{
	size_t	i;
	size_t	j;
	size_t	line_len;
	char	*remains;

	i = 0;
	line_len = gnl_ft_strlen(line);
	if (!gnl_is_in_string(line, '\n'))
		return (NULL);
	while (line[i] != '\n')
		i++;
	remains = (char *)gnl_ft_calloc(line_len - i + 1, sizeof(char));
	j = 0;
	while (line[++i])
		remains[j++] = line[i];
	return (remains);
}

char	*apply_remains(char *remains)
{
	char	*new_line;

	if (remains)
	{
		new_line = (char *)gnl_ft_calloc(gnl_ft_strlen(remains) + 1, sizeof(char));
		gnl_ft_strcpy(new_line, remains);
		free(remains);
		remains = NULL;
	}
	else
		new_line = (char *)gnl_ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	return (new_line);
}

char	*strip_line(char *line, char *to_strip)
{
	char	*tmp;
	int		idx;
	int		j;

	if (!line || !to_strip)
		return (NULL);
	idx = gnl_ft_strlen(line) - gnl_ft_strlen(to_strip);
	tmp = (char *)gnl_ft_calloc(idx + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	j = 0;
	while (j < idx)
	{
		tmp[j] = line[j];
		j++;
	}
	tmp[j] = 0;
	free(line);
	return (tmp);
}

char	*find_line(int fd, char *new_line)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*buf;

	while (!gnl_is_in_string(new_line, '\n'))
	{
		buf = (char *)gnl_ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buf);
			if (bytes_read == 0 && gnl_ft_strlen(new_line))
				break ;
			free(new_line);
			return (NULL);
		}
		tmp = gnl_ft_strjoin(new_line, buf);
		free(new_line);
		free(buf);
		new_line = tmp;
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*remains = NULL;

	if (fd < 0)
		return (NULL);
	new_line = apply_remains(remains);
	new_line = find_line(fd, new_line);
	if (!new_line)
		return (NULL);
	remains = save_remains(new_line);
	if (remains)
		new_line = strip_line(new_line, remains);
	return (new_line);
}

/* int	main(void)
{
	int fd;
	char *a, *b, *c, *d;

	fd = open("test1", O_RDONLY);
	a = get_next_line(fd);
	b = get_next_line(fd);
	//c = get_next_line(fd);
	//d = get_next_line(fd);

	printf("line 1: <%s>", a);
	printf("line 2: <%s>", b);
	//printf("line 3: <%s>", c);
	// printf("line 4: <%s>", d);

	free(a);
	free(b);
	//free(c);
	//free(d);
	return (0);
} */