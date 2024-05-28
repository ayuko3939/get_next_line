/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:36:20 by yohasega          #+#    #+#             */
/*   Updated: 2024/05/25 20:48:37 by yohasega         ###   ########.fr       */
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
# include <unistd.h> // read
// # include <limits.h>
# include <stdlib.h> // malloc

// = = = Libraries for Test = = = =
# include <fcntl.h> // open
// # include <ctype.h>
# include <stdio.h>  // fgets
// # include <string.h> // bzero
// # include <strings.h>
// = = = = = = = = = = = = = = = =

char	*get_next_line(int fd);

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
int	    ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
