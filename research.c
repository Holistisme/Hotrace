/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:08:49 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/10 03:21:04 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void		search_db(const t_bucket *db, char *key, const size_t db_size);

static inline void	write_value_found(const char *value);
static inline void	write_value_not_found(const char *key);

/* ************************************************************************** */

/**
 * @brief Researches keys from standard input in the database and writes results.
 *
 * @param db Pointer to the database array.
 * @param db_size Size of the database array.
 */
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

/**
 * @brief Searches for a key in the database and writes the corresponding value.
 *
 * @param db Pointer to the database array.
 * @param key Pointer to the key string to search for.
 * @param db_size Size of the database array.
 */
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

/**
 * @brief Checks if two strings are identical.
 *
 * @param search Pointer to the first string.
 * @param occurrence Pointer to the second string.
 * @return true if the strings are identical,
 * @return false otherwise.
 */
inline bool	is_key(const char *search, const char *occurrence)
{
	size_t	i;

	i = 0;
	if (!search || !occurrence)
		return (search == occurrence);
	while (search[i] && search[i] == occurrence[i])
		++i;
	return (search[i] == occurrence[i]);
}

/**
 * @brief Writes the found value to standard output.
 *
 * @param value Pointer to the value string.
 */
static inline void	write_value_found(const char *value)
{
	write(STDOUT_FILENO, value, get_length(value));
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * @brief Writes a "Not found" message for the given key to standard output.
 *
 * @param key Pointer to the key string.
 */
static inline void	write_value_not_found(const char *key)
{
	write(STDOUT_FILENO, key, get_length(key));
	write(STDOUT_FILENO, ": Not found.\n", 14);
}

/* ************************************************************************** */