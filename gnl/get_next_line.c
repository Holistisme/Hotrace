/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:26:58 by luflores          #+#    #+#             */
/*   Updated: 2025/12/08 15:43:24 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*mfunc(char *a, char *b, char f)
{
	char	*tmp;

	if (f == 'S')
	{
		tmp = ft_strjoin(a, b);
		free(a);
		return (tmp);
	}
	else if (f == 'F')
	{
		free(b);
		free(a);
		return (NULL);
	}
	return (NULL);
}

static char	*lookforline(char **buf)
{
	char	*nstr;
	char	*tmp;
	char	*nl_pos;

	nl_pos = ft_strchr(*buf, '\n');
	if (nl_pos)
	{
		nstr = ft_strdup(*buf, '\n');
		tmp = ft_strdup(nl_pos + 1, '\0');
		free(*buf);
		*buf = tmp;
		return (nstr);
	}
	nstr = ft_strdup(*buf, '\0');
	free(*buf);
	*buf = NULL;
	return (nstr);
}

static char	*readintobuffer(char *b, int fd)
{
	int		ret;
	char	*buf;

	if (!b)
		b = ft_calloc(1, 1);
	if (!b)
		return (NULL);
	ret = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (mfunc(b, buf, 'F'));
		buf[ret] = 0;
		b = mfunc(b, buf, 'S');
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (b);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buf[fd])
			free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	buf[fd] = readintobuffer(buf[fd], fd);
	if (!buf[fd] || buf[fd][0] == '\0')
	{
		if (buf[fd])
			free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	line = lookforline(&buf[fd]);
	return (line);
}
