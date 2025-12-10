/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:27:14 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/10 03:23:08 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* ************************************************************************** */

/**
 * @brief Set the memory object.
 *
 * @param count Number of elements to allocate.
 * @param size Size of each element.
 * @return void* Pointer to the allocated memory, or NULL on failure.
 */
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

/**
 * @brief Get the length object.
 *
 * @param str Input string.
 * @return size_t Length of the string.
 */
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