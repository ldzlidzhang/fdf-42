/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prg_ctrl_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:05 by lidzhang          #+#    #+#             */
/*   Updated: 2023/01/30 22:32:27 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	navigation_keys(int key, t_mlx *mlx)
{
	if (key == ESCAPE_ESC)
		exit_succuess(GREEN"Window shut down safely.\n\e[0m");
	else if (key == SHIFT_UP || key == SHIFT_DOWN
		|| key == SHIFT_LEFT || key == SHIFT_RIGHT)
		shift_window(mlx, key);
	else if (key == ZOOM_IN_Q || key == ZOOM_OUT_A)
		zoom_window(mlx, key);
	else if (key == RANDOM_COLOR_R)
		random_color(mlx, key);
	else if (key == RESET_PROGRAM_E)
		reset_window(mlx);
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

void	shift_window(t_mlx *mlx, int key)
{
	if (key == SHIFT_UP)
		mlx->y_shift = mlx->y_shift - 5;
	else if (key == SHIFT_DOWN)
		mlx->y_shift = mlx->y_shift + 5;
	else if (key == SHIFT_LEFT)
		mlx->x_shift = mlx->x_shift - 5;
	else if (key == SHIFT_RIGHT)
		mlx->x_shift = mlx->x_shift + 5;
	ft_render(mlx);
}

void	zoom_window(t_mlx *mlx, int key)
{
	if (key == ZOOM_IN_Q)
		mlx->xy_zoom = mlx->xy_zoom + XY_ZOOM;
	if (key == ZOOM_OUT_A && mlx->xy_zoom > 0.04)
		mlx->xy_zoom = mlx->xy_zoom - XY_ZOOM;
	ft_render(mlx);
}

void	random_color(t_mlx *mlx, int key)
{
	size_t	random_seed;

	random_seed = mlx->y0;
	random_seed = rand();
	mlx->color = rand() % random_seed;
	ft_render(mlx);
}

void	reset_window(t_mlx *mlx)
{
	get_struct_values(mlx);
	ft_render(mlx);
}
