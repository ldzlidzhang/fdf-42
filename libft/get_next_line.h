/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:21:15 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/30 21:03:12 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

# define BUFF_SIZE 2048
# define FD_MAX 4864

int		get_next_line(const int fd, char **line);
int		step2(int fd, char *s[], char **line);
char	*ft_strnew(size_t size);
void	ft_memdel(void **ap);

#endif