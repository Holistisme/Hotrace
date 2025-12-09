/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:20:44 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/09 12:42:26 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static inline void	fill_bucket(t_bucket *bucket, char *key, char *value);

/* ************************************************************************** */

t_bucket	*set_db(t_bucket *db, const size_t size, const size_t original_size)
{
	t_bucket		*new_db;
	size_t			i;
	size_t			j;
	unsigned long	hash_index;

	new_db = set_memory(size, sizeof(t_bucket));
	if (!new_db)
		return (NULL);
	i = 0;
	while (i < original_size)
	{
		hash_index = hash(db[i].key) % (size);
		if (!new_db[hash_index].key)
			fill_bucket(&new_db[hash_index], db[i].key, db[i].value);
		else
		{
			j = (hash_index + 1) % (size);
			while (new_db[j].key)
				j = (j + 1) % (size);
			fill_bucket(&new_db[j], db[i].key, db[i].value);
		}
		++i;
	}
	free(db);
	return (new_db);
}

static inline void	fill_bucket(t_bucket *bucket, char *key, char *value)
{
	bucket->key = key;
	bucket->value = value;
	bucket->key_size = get_length(key);
}

/* ************************************************************************** */