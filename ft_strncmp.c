/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luflores <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:33:18 by luflores          #+#    #+#             */
/*   Updated: 2025/10/29 14:33:21 by luflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	int					cmp;
	const unsigned char	*u1 = (const unsigned char *)s1;
	const unsigned char	*u2 = (const unsigned char *)s2;

	i = 0;
	while ((u1[i] != '\0' || u2[i] != '\0') && i < n)
	{
		if (u1[i] != u2[i])
		{
			cmp = u1[i] - u2[i];
			return (cmp);
		}
		i++;
	}
	return (0);
}

// #include <bsd/string.h>

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != 0)
// 		i++;
// 	return (i);
// }

// int main(int argc, char *argv[])
// {
// 	int i = 1;
// 	int size;
// 	int base;
// 	while (i < argc - 1)
// 	{
// 		size = ft_strncmp(argv[i],argv[i+2], ft_strlen(argv[i+2]));
// 		base = strncmp(argv[i],argv[i+2], ft_strlen(argv[i+2]));
// 		printf("FT: %d\nBASE: %d\n", size, base);
// 		i+=2;
// 	}
// 	return (0);
// }