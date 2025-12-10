/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:12:08 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/10 03:14:05 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* ************************************************************************** */

static void	delete_db(t_bucket *db, const size_t size);

/* ************************************************************************** */

/**
 * @brief Main function of the Hotrace program.
 *
 * @return int Exit status of the program.
 */
int	main(void)
{
	t_bucket	*db;
	size_t		db_size;
	size_t		new_db_size;

	db = store_input(&db_size);
	if (db == NULL)
		return (EXIT_FAILURE);
	new_db_size = db_size * 5;
	db = set_db(db, new_db_size, db_size);
	research(db, new_db_size);
	delete_db(db, new_db_size);
	return (EXIT_SUCCESS);
}

/**
 * @brief Deletes the database and frees allocated memory.
 *
 * @param db Pointer to the database array.
 * @param size Size of the database array.
 */
static void	delete_db(t_bucket *db, const size_t size)
{
	size_t	i;

	if (!db)
		return ;
	i = 0;
	while (i < size)
		delete_bucket(db[i++]);
	free(db);
}

/**
 * @brief Deletes a single bucket and frees its allocated memory.
 *
 * @param bucket The bucket to be deleted.
 */
void	delete_bucket(t_bucket bucket)
{
	if (bucket.key)
		free(bucket.key);
	if (bucket.value)
		free(bucket.value);
}

/* ************************************************************************** */