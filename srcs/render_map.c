/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:17:37 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/02/01 13:59:24 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_render_vertical(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = mlx->x;
	mlx->y0 = mlx->y;
	rotate_vertical_line(mlx, temp);
	if (mlx->y < temp->map_height)
		plot_line(mlx);
}

static void	ft_render_horizontal(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = mlx->x;
	mlx->y0 = mlx->y;
	rotate_horizontal_line(mlx, temp);
	if (mlx->x < temp->map_width)
		plot_line(mlx);
}

static void	ft_render_vertical_horizontal(t_mlx *mlx, t_mlx *temp)
{
	if (mlx->camera == 0 || mlx->camera == 1)
	{
		if (mlx->y < temp->map_height)
			ft_render_vertical(mlx, temp);
		ft_render_horizontal(mlx, temp);
	}
}

void	ft_render(t_mlx *mlx)
{
	t_mlx	temp;
	t_mlx	temp_reset;

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_menu(mlx);
	struct_copy(mlx, &temp);
	struct_copy(mlx, &temp_reset);
	copy_height_width(mlx, &temp);
	while (mlx->y <= temp.map_height)
	{
		while (mlx->x <= temp.map_width)
		{
			ft_render_vertical_horizontal(mlx, &temp);
			mlx->x++;
		}
		mlx->x = 0;
		mlx->y++;
	}
	struct_copy(&temp_reset, mlx);
	mlx->x = 0;
	mlx->y = 0;
}
