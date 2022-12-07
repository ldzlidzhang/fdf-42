/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:41:01 by lidzhang          #+#    #+#             */
/*   Updated: 2022/11/17 10:34:48 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*rest_str[4096];
	char		*line_buff;
	int			len;

	if (fd < 0)
		return (NULL);
	line_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	len = 1;
	while (!ft_strchr(rest_str[fd], '\n') && len != 0 && line_buff)
	{
		len = read(fd, line_buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(line_buff);
			return (NULL);
		}
		line_buff[len] = '\0';
		rest_str[fd] = ft_strjoin(rest_str[fd], line_buff);
	}
	free (line_buff);
	line_buff = extract_line(rest_str[fd]);
	rest_str[fd] = extract_rest(rest_str[fd]);
	return (line_buff);
}
/*
The program just reads 4096 characters per iteration.
There's no limit in the size of a line, but the may be a limit in the size of the stack
*/
