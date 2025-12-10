/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:09:24 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/10 03:18:17 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* ************************************************************************** */

#define GOLDEN_RATIO 0x9E3779B185EBCA87ULL

/* ************************************************************************** */

/**
 * @brief Computes the hash of a given string using FNV-1a algorithm.
 *
 * @param value Input string to hash.
 * @return unsigned long Computed hash value.
 */
unsigned long	hash(char *value)
{
	unsigned long	hash;
	char			*c;

	hash = GOLDEN_RATIO;
	c = value;
	while (*c)
	{
		hash ^= (unsigned long)(*c++);
		hash = (hash << 7) | (hash >> (64 - 7));
		hash *= GOLDEN_RATIO;
	}
	return (hash);
}

/* ************************************************************************** */