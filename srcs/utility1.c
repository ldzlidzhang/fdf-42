/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:32:39 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/29 22:40:04 by lidanzhang       ###   ########.fr       */
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

	width = ft_wordcount(characters[0], ' ');
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
			ft_putnbr(mlx->int_data[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
		height--;
	}
}

void	get_struct_values(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->x0 = 0;
	mlx->y0 = 0;
	mlx->x1 = mlx->x0;
	mlx->y1 = mlx->y0;
	mlx->camera = 0;
	mlx->x_shift = 0;
	mlx->y_shift = 0;
	mlx->camera = 0;
	mlx->degree_angle = 30;
	mlx->xy_zoom = 0.5;
	mlx->z_zoom = 0.03;
	mlx->x_axis = 0;
	mlx->y_axis = 0;
	mlx->z_axis = 0;
	mlx->color = 0xff000;
}
