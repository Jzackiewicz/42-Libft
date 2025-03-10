/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:32:25 by jzackiew          #+#    #+#             */
/*   Updated: 2025/03/10 18:53:58 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd, int reset_remains);
int		gnl_is_in_string(char *str, char x);
size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
size_t	gnl_ft_strcpy(char *dst, const char *src);
char	*strip_line(char *line, char *to_strip);
void	*gnl_ft_calloc(size_t nmemb, size_t size);

#endif