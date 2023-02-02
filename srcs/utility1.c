/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:32:39 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/02/01 18:47:55 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return (0);
}

int	ft_abs(int num)
{
	if (num < 0)
		num = -1 * num;
	return (num);
}

void	struct_copy(t_mlx *source, t_mlx *dest)
{
	dest->x0 = source->x0;
	dest->y0 = source->y0;
	dest->x1 = source->x1;
	dest->y1 = source->y1;
}

void	initialize_struct_values(t_mlx *mlx)
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
	mlx->degree_angle = 0;
	mlx->xy_zoom = 2;
	mlx->z_zoom = 0.5;
	mlx->x_axis = 0;
	mlx->y_axis = 0;
	mlx->z_axis = 0;
	mlx->color = 0xff000;
}

void	copy_height_width(t_mlx *mlx, t_mlx *temp)
{
	temp->map_height = mlx->map_height;
	temp->map_width = mlx->map_width;
	temp->map_height--;
	temp->map_width--;
}
