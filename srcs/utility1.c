/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:32:39 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/30 10:30:01 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	word_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (count);
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	ft_height(char **characters)
{
	int	i;

	i = 0;
	if (characters)
		while (characters[i])
			i++;
	return (i);
}

int	ft_width(char **characters)
{
	int	width;

	width = word_count(characters[0], ' ');
	return (width);
}

void	print_mlx_data(t_mlx *mlx)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	j = 0;
	width = mlx->map_width;
	height = mlx->map_height;
	while (height)
	{
		while (j < width)
		{
			ft_putnbr_fd(mlx->int_data[i][j], 1);
			ft_putstr_fd(" ", 1);
			j++;
		}
		ft_putstr_fd("\n", 1);
		j = 0;
		i++;
		height--;
	}
}
