/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prg_ctrl_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:05 by lidzhang          #+#    #+#             */
/*   Updated: 2023/02/01 19:01:48 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	program_keys(int key, t_mlx *mlx)
{
	if (key == ESCAPE_ESC)
		fdf_exit_success(GREEN"Program shut down successfully.\n\e[0m");
	else if (key == UP_K || key == DOWN_K || key == LEFT_K || key == RIGHT_K)
		shift_program(mlx, key);
	else if (key == ZOOM_IN_Q || key == ZOOM_OUT_A)
		zoom_program(mlx, key);
	else if (key == RANDOM_COLOR_R)
		random_color(mlx, key);
	else if (key == RESET_PROGRAM_E)
		reset_program(mlx);
	else if (key == CHANGE_CAMERA_C)
		change_camera(mlx);
	else if (key == ALTITUDE_INCREASE_W || key == ALTITUDE_DECREASE_S)
		change_altitude(mlx, key);
	else if (key == ROTATE_UP_I || key == ROTATE_DOWN_K)
		rotate_axis(mlx, key);
	else if (key == ROTATE_LEFT_J || key == ROTATE_RIGHT_L)
		rotate_axis(mlx, key);
	else if (key == ROTATE_SIDE_U || key == ROTATE_SIDE_O)
		rotate_axis(mlx, key);
	return (0);
}

void	random_color(t_mlx *mlx, int key)
{
	size_t	random_seed;

	random_seed = mlx->y0;
	random_seed = rand();
	mlx->color = rand() % random_seed;
	ft_render(mlx);
}

void	zoom_program(t_mlx *mlx, int key)
{
	if (key == ZOOM_IN_Q)
		mlx->xy_zoom = mlx->xy_zoom + XY_ZOOM;
	if (key == ZOOM_OUT_A && mlx->xy_zoom > 0.04)
		mlx->xy_zoom = mlx->xy_zoom - XY_ZOOM;
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

void	change_camera(t_mlx *mlx)
{
	if (mlx->camera == 0)
		mlx->camera = 1;
	else if (mlx->camera == 1)
		mlx->camera = 0;
	ft_render(mlx);
}
