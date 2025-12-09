/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:08:49 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/09 13:36:57 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void		search_db(const t_bucket *db, char *key, const size_t db_size);

static inline bool	is_key(const char *search, const char *occurrence);
static inline void	write_value_found(const char *value);
static inline void	write_value_not_found(const char *key);

//TODO: Double write can be optimized with a single write call

/* ************************************************************************** */

void	research(const t_bucket *db, const size_t db_size)
{
	char	*key;

	while (true)
	{
		key = read_next_input();
		if (!key || !key[0])
		{
			free(key);
			break ;
		}
		search_db(db, key, db_size);
		free(key);
	}
}

/* ************************************************************************** */

static void	search_db(const t_bucket *db, char *key, const size_t db_size)
{
	const size_t	search_size = get_length(key);
	unsigned long	i;

	i = hash(key) % db_size;
	while (true)
	{
		if (!db[i].key)
			return (write_value_not_found(key));
		if (db[i].key_size == search_size && is_key(db[i].key, key))
			return (write_value_found(db[i].value));
		i = (i + 1) % db_size;
	}
}

static inline bool	is_key(const char *search, const char *occurrence)
{
	size_t	i;

	i = 0;
	if (!search || !occurrence)
		return (search == occurrence);
	while (search[i] && search[i] == occurrence[i])
		++i;
	return (search[i] == occurrence[i]);
}

static inline void	write_value_found(const char *value)
{
	write(STDOUT_FILENO, value, get_length(value));
	write(STDOUT_FILENO, "\n", 1);
}

static inline void	write_value_not_found(const char *key)
{
	write(STDERR_FILENO, key, get_length(key));
	write(STDERR_FILENO, ": Not found.\n", 14);
}

/* ************************************************************************** */