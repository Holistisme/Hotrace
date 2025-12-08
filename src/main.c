/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:12:08 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/08 16:28:34 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "database.h"
#include <stdio.h>
#include <stdbool.h>

static void printf_database(t_database *db);

int	main(void)
{
	t_database *db = fill_database();
	printf_database(db);
	free_db(db);
	return (0);
}

static void printf_database(t_database *db)
{
	t_database *current = db;

	while (current)
	{
		printf("Name: %s", current->name);
		printf("Value: %s", current->value);
		current = current->next;
	}
}