/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:21:33 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/30 21:03:20 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*memory;

	i = 0;
	memory = (char *)malloc(sizeof(char) * (size + 1));
	if (!(memory))
		return (NULL);
	else
	{
		while (i <= size)
			memory[i++] = 0;
	}
	return (memory);
}

// char	*ft_strjoin_gnl(char *rest_str, char *buff)
// {
// 	unsigned int	i;
// 	unsigned int	j;
// 	char			*dest;

// 	if (!rest_str)
// 	{
// 		rest_str = (char *)malloc(1 * sizeof(char));
// 		rest_str[0] = '\0';
// 	}
// 	if (!rest_str || !buff)
// 		return (NULL);
// 	i = ft_strlen(rest_str);
// 	j = ft_strlen(buff);
// 	dest = malloc(sizeof(char) * (i + j + 1));
// 	i = -1;
// 	j = -1;
// 	while (rest_str[++i])
// 		dest[i] = rest_str[i];
// 	while (buff[++j])
// 		dest[i++] = buff[j];
// 	dest[i] = '\0';
// 	free(rest_str);
// 	return (dest);
// }

void	ft_memdel(void **ap)
{
	if (ap)
	{
		(free(*ap));
		*ap = NULL;
	}
}
