/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prg_ctrl_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:06:26 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/29 23:22:24 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_camera(t_mlx *mlx)
{
	if (mlx->camera == 0)
		mlx->camera = 1;
	else if (mlx->camera == 1)
		mlx->camera = 0;
	ft_render(mlx);
}

void	rotate_axis(t_mlx *mlx, int key)
{
	if (key == ROTATE_UP_I)
		mlx->x_axis = mlx->x_axis + 0.02;
	else if (key == ROTATE_DOWN_K)
		mlx->x_axis = mlx->x_axis - 0.02;
	else if (key == ROTATE_LEFT_J)
		mlx->y_axis = mlx->y_axis + 0.02;
	else if (key == ROTATE_RIGHT_L)
		mlx->y_axis = mlx->y_axis - 0.02;
	else if (key == ROTATE_SIDE_U)
		mlx->z_axis = mlx->z_axis + 0.02;
	else if (key == ROTATE_SIDE_O)
		mlx->z_axis = mlx->z_axis - 0.02;
	ft_render(mlx);
}

void	change_altitude(t_mlx *mlx, int key)
{
	if (key == ALTITUDE_INCREASE_W)
		mlx->z_zoom = mlx->z_zoom + Z_ZOOM;
	else if (key == ALTITUDE_DECREASE_S)
		mlx->z_zoom = mlx->z_zoom - Z_ZOOM;
	ft_render(mlx);
}
