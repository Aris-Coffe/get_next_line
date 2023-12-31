/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalatzas <aalatzas@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 05:00:27 by aalatzas          #+#    #+#             */
/*   Updated: 2023/11/01 20:44:20 by aalatzas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] != '\0')
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	maxlen;

	maxlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = ft_calloc(maxlen, 1);
	if (!newstr)
		return (NULL);
	ft_strlcat(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(newstr, s2, maxlen);
	if (!newstr[0] && newstr[0] == '\0')
	{
		free (newstr);
		return (NULL);
	}
	return (newstr);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	char		*str;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	str = (char *)malloc(count * size);
	if (!str)
		return (NULL);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	dstfull;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dstfull = dstlen + srclen;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (dstlen < dstsize - 1 && *src)
	{
		dst[dstlen] = *src++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (dstfull);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (src1 == 0 && dst1 == 0)
		return (0);
	if (dst1 <= src1)
	{
		while (len-- > 0)
			*dst1++ = *src1++;
	}
	else if (dst1 > src1)
	{
		dst1 += len -1;
		src1 += len -1;
		while (len-- > 0)
			*dst1-- = *src1--;
	}
	return (dst);
}
