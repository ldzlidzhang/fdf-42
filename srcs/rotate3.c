/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:02:43 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/02/01 14:44:06 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	normalize_value(t_mlx *mlx)
{
	int	height;
	int	width;

	height = P_HEIGHT / mlx->map_height;
	width = P_WIDTH / mlx->map_width;
	if (height < width)
		return (height);
	else if (width <= height)
		return (width);
	return (0);
}

static void	implement_transformations(t_mlx *mlx, int normalize)
{
	adjust_zoom(mlx, normalize);
	rotate_xyz_axis(mlx);
	change_projection_view(mlx);
	shift_and_centeralize_map(mlx);
}

void	rotate_vertical_line(t_mlx *mlx, t_mlx *temp)
{
	int	normalize;

	normalize = normalize_value(mlx);
	if (mlx->y < temp->map_height)
	{
		mlx->z0 = mlx->int_data[mlx->y][mlx->x] * mlx->z_zoom * normalize;
		mlx->z1 = mlx->int_data[mlx->y + 1][mlx->x] * mlx->z_zoom * normalize;
	}
	mlx->x1 = mlx->x0;
	mlx->y1 = mlx->y0 + 1;
	implement_transformations(mlx, normalize);
}

void	rotate_horizontal_line(t_mlx *mlx, t_mlx *temp)
{
	int	normalize;

	normalize = normalize_value(mlx);
	if (mlx->x < temp->map_width)
	{
		mlx->z0 = mlx->int_data[mlx->y][mlx->x] * mlx->z_zoom * normalize;
		mlx->z1 = mlx->int_data[mlx->y][mlx->x + 1] * mlx->z_zoom * normalize;
	}
	mlx->x1 = mlx->x0 + 1;
	mlx->y1 = mlx->y0;
	implement_transformations(mlx, normalize);
}
