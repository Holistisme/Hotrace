/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:27:14 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/09 23:27:43 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* ************************************************************************** */

void	*set_memory(const size_t count, const size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	const size_t	total_size = count * size;

	if (total_size / size != count)
		return (NULL);
	ptr = malloc(total_size);
	i = 0;
	if (ptr)
		while (i < total_size)
			ptr[i++] = 0;
	return (ptr);
}

inline size_t	get_length(const char *str)
{
	size_t	len;

	len = 0;
	if (str)
		while (str[len])
			++len;
	return (len);
}

/* ************************************************************************** */