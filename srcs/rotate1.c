/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:57:23 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/02/01 14:46:05 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotation_matrix(t_mlx *mlx, int *x, int *y, int z)
{
	int		temp_x;
	int		temp_y;
	double	radian;

	temp_x = *x;
	temp_y = *y;
	if (mlx->camera == 0)
		mlx->degree_angle = 30;
	else if (mlx->camera == 1)
		mlx->degree_angle = 15;
	radian = (mlx->degree_angle) * (M_PI / 180);
	*x = (temp_x - temp_y) * cos(radian);
	*y = -z + (temp_x + temp_y) * sin(radian);
}

void	change_projection_view(t_mlx *mlx)
{
	rotation_matrix(mlx, &mlx->x0, &mlx->y0, mlx->z0);
	rotation_matrix(mlx, &mlx->x1, &mlx->y1, mlx->z1);
}

void	adjust_zoom(t_mlx *mlx, int normalize)
{
	mlx->x0 = mlx->x0 * mlx->xy_zoom * normalize;
	mlx->x1 = mlx->x1 * mlx->xy_zoom * normalize;
	mlx->y0 = mlx->y0 * mlx->xy_zoom * normalize;
	mlx->y1 = mlx->y1 * mlx->xy_zoom * normalize;
}

void	shift_and_centeralize_map(t_mlx *mlx)
{
	mlx->x0 = mlx->x0 + mlx->x_shift + (P_WIDTH / 2.5);
	mlx->x1 = mlx->x1 + mlx->x_shift + (P_WIDTH / 2.5);
	mlx->y0 = mlx->y0 + mlx->y_shift + (P_HEIGHT / 4);
	mlx->y1 = mlx->y1 + mlx->y_shift + (P_HEIGHT / 4);
}
