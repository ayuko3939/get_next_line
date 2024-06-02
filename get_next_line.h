/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:50:23 by yohasega          #+#    #+#             */
/*   Updated: 2024/06/02 17:58:30 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h> // malloc
# include <unistd.h> // read ssize_t
// # include <stdbool.h>
// # include <stddef.h>
// # include <stdint.h> // SIZE_MAX
// # include <limits.h>

// #include "leakdetect.h"
// #define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__)
// #define free leak_detect_free

char	*free_nullset(char **str);
int		read_from_fd(int fd, char **temp);
char	*get_newline(char *str);
int		remove_line_from_temp(char **str);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strjoin(char **s1, char *s2);

#endif
