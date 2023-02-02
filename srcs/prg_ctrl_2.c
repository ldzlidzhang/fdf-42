/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prg_ctrl_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:06:26 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/02/01 19:01:50 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_program(t_mlx *mlx, int key)
{
	if (key == UP_K)
		mlx->y_shift = mlx->y_shift - SHIFT_SCALE;
	else if (key == DOWN_K)
		mlx->y_shift = mlx->y_shift + SHIFT_SCALE;
	else if (key == LEFT_K)
		mlx->x_shift = mlx->x_shift - SHIFT_SCALE;
	else if (key == RIGHT_K)
		mlx->x_shift = mlx->x_shift + SHIFT_SCALE;
	ft_render(mlx);
}

void	rotate_axis(t_mlx *mlx, int key)
{
	if (key == ROTATE_UP_I)
		mlx->x_axis = mlx->x_axis + ROTATE_ANGLE;
	else if (key == ROTATE_DOWN_K)
		mlx->x_axis = mlx->x_axis - ROTATE_ANGLE;
	else if (key == ROTATE_LEFT_J)
		mlx->y_axis = mlx->y_axis + ROTATE_ANGLE;
	else if (key == ROTATE_RIGHT_L)
		mlx->y_axis = mlx->y_axis - ROTATE_ANGLE;
	else if (key == ROTATE_SIDE_U)
		mlx->z_axis = mlx->z_axis + ROTATE_ANGLE;
	else if (key == ROTATE_SIDE_O)
		mlx->z_axis = mlx->z_axis - ROTATE_ANGLE;
	ft_render(mlx);
}

void	reset_program(t_mlx *mlx)
{
	initialize_struct_values(mlx);
	ft_render(mlx);
}
