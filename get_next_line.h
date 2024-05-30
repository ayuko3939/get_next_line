/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:36:20 by yohasega          #+#    #+#             */
/*   Updated: 2024/05/30 14:19:51 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// # include <stdbool.h>
// # include <stddef.h>
// # include <stdint.h> // SIZE_MAX
# include <unistd.h> // read ssize_t
// # include <limits.h>
# include <stdlib.h> // malloc

// = = = Libraries for Test = = = =
# include <fcntl.h> // open
# include <stdio.h> // fgets printf
// # include <ctype.h>
// # include <string.h> // bzero
// # include <strings.h>
// = = = = = = = = = = = = = = = =

char	*read_from_fd(int fd, char *temp);
char	*get_newline(char *str);
char	*remove_line_from_temp(char *temp, size_t line_end);
char	*get_next_line(int fd);

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
#endif
