/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:47:19 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/08 16:28:18 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_H
# define DATABASE_H

typedef struct s_database
{
	char				*name;
	char				*value;
	struct s_database	*next;
}	t_database;

t_database	*fill_database(void);
void	free_db(t_database *db);

#endif

/* ************************************************************************** */