/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:41:34 by lidzhang          #+#    #+#             */
/*   Updated: 2023/01/30 20:19:54 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define BUFFER_SIZE 2048

char	*get_next_line(int fd);
char	*extract_line(char *rest_str);
char	*extract_rest(char *rest_str);
char	*ft_read_to_rest_str(int fd, char *rest_str);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *rest_str, char *buff);
size_t	ft_strlen_gnl(const char *str);

#endif
