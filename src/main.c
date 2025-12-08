/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:12:08 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/08 15:54:55 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "database.h"
#include <stdio.h>
#include <stdbool.h>

static t_database *fill_database();
// static void printf_database(t_database *db);

int	main(void)
{
	t_database *db = fill_database();
	// printf_database(db);
	return (0);
}

static t_database *fill_database()
{
	t_database *db;
	t_database *prev;
	t_database *new_data;
	int i = 0;
	char *keyword;
	char *value;

	db = NULL;
	while (true)
	{
		keyword = get_next_line(STDIN_FILENO);
		if (ft_strlen(keyword, '\0') == 1) // \n
			break;
		value = get_next_line(STDIN_FILENO);
		if (!db)
		{
			db = ft_calloc(1, sizeof(t_database));
			db->name = keyword;
			db->value = value;
			db->next = NULL;
			prev = db;
		}
		else
		{
			new_data = ft_calloc(1, sizeof(t_database));
			new_data->name = keyword;
			new_data->value = value;
			new_data->next = NULL;
			prev->next = new_data;
			prev = new_data;
		}
		i++;
	}
	return (db);
}

// static void printf_database(t_database *db)
// {
// 	t_database *current = db;

// 	while (current)
// 	{
// 		printf("Name: %s", current->name);
// 		printf("Value: %s", current->value);
// 		current = current->next;
// 	}
// }