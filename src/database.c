/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:02:23 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/08 16:37:19 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "database.h"
#include "get_next_line.h"
#include <stdbool.h>

/* ************************************************************************** */

static inline void		free_data(t_database *data);
static inline t_database	*add_data(void);

/* ************************************************************************** */

t_database	*fill_database(void)
{
	t_database	*db;
	t_database	*prev;
	t_database	*new_data;

	db = NULL;
	while (true)
	{
		new_data = add_data();
		if (!new_data)
		{
			get_next_line(-1);
			break ;
		}
			
		if (!db)
		{
			db = new_data;
			prev = db;
			continue ;
		}
		prev->next = new_data;
		prev = new_data;
	}
	return (db);
}

/* ************************************************************************** */

static inline t_database	*add_data(void)
{
	t_database	*new;

	new = ft_calloc(1, sizeof(t_database));
	new->name = get_next_line(STDIN_FILENO);
	new->value = get_next_line(STDIN_FILENO);
	new->next = NULL;
	if (ft_strlen(new->name, '\0') == 1
		|| ft_strlen(new->value, '\0') == 1)
	{
		free_data(new);
		new = NULL;
	}
	return (new);
}

/* ************************************************************************** */

void	free_db(t_database *db)
{
	t_database	*current;
	t_database	*next;

	current = db;
	while (current)
	{
		next = current->next;
		free_data(current);
		current = next;
	}
}

/* ************************************************************************** */

static inline void	free_data(t_database *data)
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

/* ************************************************************************** */