/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:02:23 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/08 16:04:42 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "database.h"

/* ************************************************************************** */

static t_database *fill_database()
{
	t_database	*db;
	t_database	*prev;
	t_database	*new_data;

	db = NULL;
	while (true)
	{
		new_data = ft_calloc(1, sizeof(t_database));
		new_data->name = get_next_line(STDIN_FILENO);
		new_data->value = get_next_line(STDIN_FILENO);
		new_data->next = NULL;
		if (ft_strlen(new_data->name, '\0') == 1
			|| ft_strlen(new_data->value, '\0') == 1)
		{
			free(new_data->name);
			free(new_data->value);
			free(new_data);
			break ;
		}
		if (!db)
		{
			db = new_data;
			prev = db;
		}
		else
		{
			prev->next = new_data;
			prev = new_data;
		}
	}
	return (db);
}

/* ************************************************************************** */

void free_db(t_database *db)
{
	
}

void	free_data(t_database *data)
{
	if (data)
	{
		if (data->name)
			free(data->name);
		if (data->value)
			free(data->value);
		free(data);
	}
}