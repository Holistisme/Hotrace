/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:50:00 by aheitz            #+#    #+#             */
/*   Updated: 2025/12/10 03:16:57 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static char		*update_input(char *input, char c,
					size_t *len, size_t *capacity);

static inline char	*realloc_memory(char *old, size_t old_size);
static inline void	write_read_error(const char *error);

/* ************************************************************************** */

/**
 * @brief Reads the next line of input from standard input.
 *
 * @return char* Pointer to the read line (dynamically allocated), NULL on error.
 */
char	*read_next_input(void)
{
	char	buffer[1];
	char	*input;
	ssize_t	read_bytes;
	size_t	len;
	size_t	capacity;

	len = 0;
	capacity = 32;
	input = set_memory(capacity, sizeof(char));
	while (input)
	{
		read_bytes = read(STDIN_FILENO, buffer, 1);
		if (read_bytes < 0)
		{
			write_read_error(NULL);
			if (input)
				free(input);
			return (NULL);
		}
		if (read_bytes == 0 || buffer[0] == '\n')
			break ;
		input = update_input(input, buffer[0], &len, &capacity);
	}
	return (input);
}

/* ************************************************************************** */

/**
 * @brief Updates input string with new character, reallocating memory if needed.
 *
 * @param input Current input string.
 * @param c Character to append.
 * @param len Pointer to current length of the input string.
 * @param capacity Pointer to current capacity of the input string.
 * @return char* Updated input string, or NULL on allocation failure.
 */
static char	*update_input(char *input, char c, size_t *len, size_t *capacity)
{
	if (*len + 1 >= *capacity)
	{
		*capacity += 32;
		input = realloc_memory(input, *len);
		if (!input)
		{
			write_read_error("Memory allocation failed\n");
			return (NULL);
		}
	}
	input[*len] = c;
	(*len)++;
	return (input);
}

/**
 * @brief Reallocates memory for the input string to increase its capacity.
 *
 * @param old Pointer to the old input string.
 * @param old_size Current size of the old input string.
 * @return char* Pointer to the newly allocated input string.
 */
static inline char	*realloc_memory(char *old, size_t old_size)
{
	char	*new;
	size_t	i;

	new = set_memory(old_size + 32, sizeof(char));
	i = 0;
	while (i < old_size)
	{
		new[i] = old[i];
		++i;
	}
	free(old);
	return (new);
}

/**
 * @brief Writes an error message to standard error.
 *
 * @param error Error message to write, or NULL to use strerror(errno).
 */
static inline void	write_read_error(const char *error)
{
	write(STDERR_FILENO, "ERROR: ", 8);
	if (error)
		write(STDERR_FILENO, error, get_length(error));
	else
	{
		write(STDERR_FILENO, strerror(errno), get_length(strerror(errno)));
		write(STDERR_FILENO, "\n", 1);
	}
}

/* ************************************************************************** */