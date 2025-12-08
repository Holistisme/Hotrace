/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luflores <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:27:32 by luflores          #+#    #+#             */
/*   Updated: 2025/11/06 15:27:33 by luflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != c)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	cast_c;
	int		i;

	cast_c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cast_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cast_c)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc(size_t ec, size_t es)
{
	void	*ptr;
	size_t	i;

	i = ec * es;
	if (es && (i / es != ec))
		return (NULL);
	ptr = malloc(ec * es);
	if (ptr == NULL)
		return (NULL);
	while (i-- > 0)
		((unsigned char *)ptr)[i] = 0;
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1, 0);
	len2 = ft_strlen(s2, 0);
	dest = malloc(len1 + len2 + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src, char c)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src, c) + 1;
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
