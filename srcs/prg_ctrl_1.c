/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prg_ctrl_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:05 by lidzhang          #+#    #+#             */
/*   Updated: 2023/01/26 11:56:53 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	program_keys(int key, t_mlx *mlx)
{
	if (key == ESCAPE_ESC)
		ft_exit_success(GREEN"Program shut down successfully.\n");
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
