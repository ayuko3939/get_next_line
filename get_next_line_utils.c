/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:36:23 by yohasega          #+#    #+#             */
/*   Updated: 2024/05/29 22:46:10 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// new ft_calloc (uninclude: bzero memset)
void	*ft_calloc(size_t count, size_t size)
{
	void			*array;
	size_t			i;
	unsigned char	*s;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	array = (void *)malloc(count * size);
	if (array == NULL)
		return (NULL);
	s = (unsigned char *)array;
	i = 0;
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return (array);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// new ft_strchr (add : NULLguard)
char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	// if (s == NULL)
	// 	return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	length;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	length = len_s1 + len_s2;
	new_str = (char *)ft_calloc(1, sizeof(char) * (length + 1));
	if (new_str == NULL)
		return (new_str);
	ft_memcpy((void *)new_str, (void *)s1, len_s1);
	ft_memcpy((void *)new_str + len_s1, (void *)s2, len_s2);
	return (new_str);
}