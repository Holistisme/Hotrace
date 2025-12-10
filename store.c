/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:02:23 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/10 03:22:06 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* ************************************************************************** */

static inline t_bucket	add_bucket(void);
static inline t_bucket	*add_db_memory(t_bucket *db, const size_t cap);

/* ************************************************************************** */

/**
 * @brief Stores input key-value pairs into a dynamically allocated database.
 *
 * @param size Pointer to store the number of stored key-value pairs.
 * @return t_bucket* Pointer to the dynamically allocated database array.
 */
t_bucket	*store_input(size_t *size)
{
	t_bucket	*db;
	t_bucket	new;
	size_t		cap;

	cap = 1;
	db = set_memory(cap, sizeof(t_bucket));
	if (!db)
		return (NULL);
	*size = 0;
	while (true)
	{
		new = add_bucket();
		if (!new.key || !get_length(new.key) || !new.value)
			break ;
		if (*size == cap)
		{
			db = add_db_memory(db, cap);
			if (!db)
				return (NULL);
			cap = cap * 2 + 1;
		}
		db[(*size)++] = new;
	}
	delete_bucket(new);
	return (db);
}

/* ************************************************************************** */

/**
 * @brief Reads a key-value pair from input and returns it as a t_bucket.
 *
 * @return t_bucket The read key-value pair.
 */
static inline t_bucket	add_bucket(void)
{
	t_bucket	new;

	new.key = NULL;
	new.value = NULL;
	new.key = read_next_input();
	if (new.key && get_length(new.key))
		new.value = read_next_input();
	return (new);
}

/**
 * @brief Doubles the size of the database array and copies existing entries.
 *
 * @param db Pointer to the current database array.
 * @param cap Current capacity of the database array.
 * @return t_bucket* Pointer to the newly allocated database array.
 */
static inline t_bucket	*add_db_memory(t_bucket *db, const size_t cap)
{
	t_bucket	*new_db;
	size_t		i;

	new_db = set_memory(cap * 2 + 1, sizeof(t_bucket));
	if (!new_db)
	{
		free(db);
		return (NULL);
	}
	i = 0;
	while (i < cap)
	{
		new_db[i] = db[i];
		++i;
	}
	free(db);
	return (new_db);
}

/* ************************************************************************** */