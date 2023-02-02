/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:57:31 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/02/01 14:44:50 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x_axis(t_mlx *mlx, int *y, int *z, double x_axis)
{
	int	temp_y;
	int	temp_z;

	temp_y = (*y * cos(x_axis)) - (*z * sin(x_axis));
	temp_z = (*y * sin(x_axis)) + (*z * cos(x_axis));
	*y = temp_y;
	*z = temp_z;
}

static void	rotate_y_axis(t_mlx *mlx, int *x, int *z, double y_axis)
{
	int	temp_x;
	int	temp_z;

	temp_x = (*x * cos(y_axis)) - (*z * sin(y_axis));
	temp_z = (*x * sin(y_axis)) + (*z * cos(y_axis));
	*x = temp_x;
	*z = temp_z;
}

static void	rotate_z_axis(t_mlx *mlx, int *x, int *y, double z_axis)
{
	int	temp_x;
	int	temp_y;

	temp_x = (*x * cos(z_axis)) - (*y * sin(z_axis));
	temp_y = (*x * sin(z_axis)) + (*y * cos(z_axis));
	*x = temp_x;
	*y = temp_y;
}

void	rotate_xyz_axis(t_mlx *mlx)
{
	rotate_x_axis(mlx, &mlx->y0, &mlx->z0, mlx->x_axis);
	rotate_x_axis(mlx, &mlx->y1, &mlx->z1, mlx->x_axis);
	rotate_y_axis(mlx, &mlx->x0, &mlx->y0, mlx->y_axis);
	rotate_y_axis(mlx, &mlx->x1, &mlx->y1, mlx->y_axis);
	rotate_z_axis(mlx, &mlx->x0, &mlx->y0, mlx->z_axis);
	rotate_z_axis(mlx, &mlx->x1, &mlx->y1, mlx->z_axis);
}
