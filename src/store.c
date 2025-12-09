/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:02:23 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/09 12:09:39 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* ************************************************************************** */

static inline t_bucket	add_bucket(void);
static inline t_bucket	*add_db_memory(t_bucket *db, const size_t cap);

/* ************************************************************************** */

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