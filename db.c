/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:20:44 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/10 02:43:02 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static inline void	fill_bucket(t_bucket *bucket, char *key, char *value);

/* ************************************************************************** */

t_bucket	*set_db(t_bucket *db, const size_t size, const size_t original_size)
{
	t_bucket		*new;
	size_t			i;
	size_t			j;
	unsigned long	hash_index;

	new = set_memory(size, sizeof(t_bucket));
	if (!new)
		return (NULL);
	i = 0;
	while (i < original_size)
	{
		hash_index = hash(db[i].key) % (size);
		if (!new[hash_index].key || is_key(db[i].key, new[hash_index].key))
			fill_bucket(&new[hash_index], db[i].key, db[i].value);
		else
		{
			j = (hash_index + 1) % (size);
			while (new[j].key && !is_key(db[i].key, new[j].key))
				j = (j + 1) % (size);
			fill_bucket(&new[j], db[i].key, db[i].value);
		}
		++i;
	}
	free(db);
	return (new);
}

static inline void	fill_bucket(t_bucket *bucket, char *key, char *value)
{
	if (bucket->key)
	{
		free(bucket->key);
		free(bucket->value);
	}
	bucket->key = key;
	bucket->value = value;
	bucket->key_size = get_length(key);
}

/* ************************************************************************** */