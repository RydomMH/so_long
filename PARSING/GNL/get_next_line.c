/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:26:53 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/06 13:18:21 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_stash(char *stash, char *buffer)
{
	char	*temp;

	temp = NULL;
	temp = stash;
	stash = ft_strjoin(temp, buffer);
	if (stash == NULL)
		return (free(temp), temp = NULL, NULL);
	free(temp);
	temp = NULL;
	return (stash);
}

char	*stackstash(char *stash, char *buffer, ssize_t r_b, int *f)
{
	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * r_b + 1);
		if (stash == NULL)
			return (free(buffer), buffer = NULL, *f = -1, NULL);
		stash[r_b] = '\0';
		stash = ft_strcpy(stash, buffer);
	}
	else
	{
		stash = update_stash(stash, buffer);
		if (stash == NULL)
			return (free(buffer), buffer = NULL, *f = -1, NULL);
	}
	return (stash);
}

char	*stackbuffer(char *sta, int fd)
{
	char	*buf;
	int		flag;
	ssize_t	r_b;

	r_b = 1;
	buf = NULL;
	flag = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (free(sta), sta = NULL, NULL);
	buf[BUFFER_SIZE] = '\0';
	while (r_b != 0)
	{
		r_b = read(fd, buf, BUFFER_SIZE);
		if (r_b < 0)
			return (free(buf), buf = NULL, free(sta), sta = NULL, NULL);
		buf[r_b] = '\0';
		sta = stackstash(sta, buf, r_b, &flag);
		if (flag == -1 && sta == NULL)
			return (NULL);
	}
	return (free(buf), buf = NULL, sta);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	stash = stackbuffer(stash, fd);
	if (stash == NULL)
		return (NULL);
	return (stash);
}
