/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:47:19 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/10 02:07:29 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

/* ************************************************************************** */

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

/* ************************************************************************** */

typedef struct s_bucket
{
	char	*key;
	char	*value;
	size_t	key_size;
}	t_bucket;

/* ************************************************************************** */

char			*read_next_input(void);

size_t			get_length(const char *str);
void			*set_memory(size_t count, size_t size);
void			delete_bucket(t_bucket bucket);

void			research(const t_bucket *db, const size_t db_size);
unsigned long	hash( char *str);
bool			is_key(const char *search, const char *occurrence);

t_bucket		*store_input(size_t *size);
t_bucket		*set_db(t_bucket *db, const size_t size,
					const size_t original_size);

#endif

/* ************************************************************************** */