/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:12:08 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/09 13:36:28 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* ************************************************************************** */

static void	delete_db(t_bucket *db, const size_t size);

/* ************************************************************************** */

// TODO: To delete

#include <sys/time.h>

double now(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1e6;
}

// TODO: To delete

int	main(void)
{
	t_bucket	*db;
	size_t		db_size;
	size_t		new_db_size;

	db = store_input(&db_size);
	if (db == NULL)
		return (EXIT_FAILURE);
	new_db_size = db_size * 2;
	if (new_db_size < 1024)
		new_db_size = 1024;
	db = set_db(db, new_db_size, db_size);
	double start = now(); // TODO: To delete
	research(db, new_db_size);
	double end = now(); // TODO: To delete
	fprintf(stderr, "Time taken for research: %f seconds\n", end - start);
	delete_db(db, new_db_size);
	return (EXIT_SUCCESS);
}

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

void	delete_bucket(t_bucket bucket)
{
	if (bucket.key)
		free(bucket.key);
	if (bucket.value)
		free(bucket.value);
}

/* ************************************************************************** */