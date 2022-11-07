/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:03:23 by woumecht          #+#    #+#             */
/*   Updated: 2022/11/07 17:17:39 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len)
	{
		*p++ = (unsigned char)c;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_memset(ptr, 0, count * size);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;
	size_t	len_str;

	if (s == NULL)
		return (NULL);
	len_str = ft_strlen(s);
	if (start >= len_str)
		return (ft_calloc(1,1));
	if (len_str - start < len)
		len = len_str - start;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		ptr[j] = ((char *)s)[start];
		start++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[j++] = s2[i];
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
