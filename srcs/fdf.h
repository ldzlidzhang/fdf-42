/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:32:51 by lidzhang          #+#    #+#             */
/*   Updated: 2023/01/26 13:04:23 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./resource/minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

/*Front Color*/
# define GREEN "\33[1;32m"
# define YELLOW "\33[1;33m"
# define CYAN "\33[1;36m"

/*Graph Window*/
# define G_WIDTH 1280
# define G_HEIGHT 720

/*Keys Nevigate Program*/
# define UP_K 126
# define DOWN_K 125
# define LEFT_K 123
# define RIGHT_K 124

# define ZOOM_IN_Q 12
# define ZOOM_OUT_A 0

# define ALTITUDE_INCREASE_W 13
# define ALTITUDE_DECREASE_S 1

# define RANDOM_COLOR_R 15
# define RESET_PROGRAM_E 14
# define CHANGE_CAMERA_C 8
# define ESCAPE_ESC 53

# define ROTATE_UP_I 34
# define ROTATE_LEFT_J 38
# define ROTATE_DOWN_K 40
# define ROTATE_RIGHT_L 37
# define ROTATE_SIDE_U 32
# define ROTATE_SIDE_O 31

/*date structure*/
typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	size_t		color;
	int			x0;
	int			y0;
	int			z0;
	int			x1;
	int			y1;
	int			z1;
	int			dx;
	int			dy;
	int			delta_error;
	int			xi;
	int			yi;
	int			**int_data;
	int			map_width;
	int			map_height;
	int			camera;
	int			x_shift;
	int			y_shift;
	double		xy_zoom;
	double		z_zoom;
	double		degree_angle;
	double		x_axis;
	double		y_axis;
	double		z_axis;
	double		map_min;
}				t_mlx;

/*Program control*/
int	program_key(int key, t_mlx *mlx);

/*Warning message*/
void	exit_succuess(char *str);
void	ft_exit(char *str);
void	ft_exit_dir(char *str);
void	invalid_file(int return_value, char *argv);
void	exit_no_file(char *argv);

#endif