/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:32:57 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/23 13:10:54 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_in_string(char *str, char x)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (x == str[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_string;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	i = -1;
	while (s1[++i])
		new_string[i] = s1[i];
	i = -1;
	while (s2[++i])
		new_string[i + s1_len] = s2[i];
	new_string[i + s1_len] = 0;
	return (new_string);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	i = 0;
	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	while (src[i] != 0)
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*data;
	unsigned char	*p;
	size_t			n;
	size_t			i;

	n = 0;
	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb && (nmemb * size) / nmemb != size)
		return (NULL);
	data = (void *)malloc(nmemb * size);
	if (!data)
		return (NULL);
	n = nmemb * size;
	p = (unsigned char *)data;
	i = 0;
	while (n > 0)
	{
		p[i] = '\0';
		i++;
		n--;
	}
	return (data);
}
