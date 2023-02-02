/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:32:51 by lidzhang          #+#    #+#             */
/*   Updated: 2023/02/01 19:01:13 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../resource/minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
// # include <stdio.h>

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

# define GREEN "\33[1;32m"
# define YELLOW "\33[1;33m"
# define CYAN "\33[1;36m"

# define P_WIDTH 1280
# define P_HEIGHT 720
# define XY_ZOOM 3
# define Z_ZOOM 1
# define SHIFT_SCALE 100
# define ROTATE_ANGLE 0.5

/*date structure*/
typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
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
	size_t		color;
	double		xy_zoom;
	double		z_zoom;
	double		degree_angle;
	double		x_axis;
	double		y_axis;
	double		z_axis;
	double		map_min;
}				t_mlx;

/* main.c */
int				main(int argc, char **argv);

/* plot_line.c */
void			plot_line(t_mlx *mlx);

/* warning_messages.c */
void			fdf_exit_no_file(char *argv);
void			fdf_exit_dir(char *str);
void			fdf_exit(char *str);
void			fdf_exit_success(char *str);
void			invalid_file_message(int ft_return, char *argv);

/* read_data.c */
int				map_valid(int fd, int height, char *argv);
int				**str_to_int(char **characters);
char			**file_to_str(int fd, int height, char *argv);

/* render_map.c */
void			ft_render(t_mlx *mlx);

/* prg_ctrl_1.c */
int				program_keys(int key, t_mlx *mlx);
void			random_color(t_mlx *mlx, int key);
void			zoom_program(t_mlx *mlx, int key);
void			change_altitude(t_mlx *mlx, int key);
void			change_camera(t_mlx *mlx);

/* prg_ctrl_2.c */
void			rotate_axis(t_mlx *mlx, int key);
void			shift_program(t_mlx *mlx, int key);
void			reset_program(t_mlx *mlx);

/* rotate1.c */
void			change_projection_view(t_mlx *mlx);
void			shift_and_centeralize_map(t_mlx *mlx);
void			adjust_zoom(t_mlx *mlx, int normalize);

/* rotate2.c */
void			rotate_xyz_axis(t_mlx *mlx);

/* rotate3.c */
void			rotate_vertical_line(t_mlx *mlx, t_mlx *temp);
void			rotate_horizontal_line(t_mlx *mlx, t_mlx *temp);

/* menu.c */
void			ft_menu(t_mlx *mlx);

/* utility1.c*/
int				ft_swap(int *a, int *b);
int				ft_abs(int num);
void			struct_copy(t_mlx *source, t_mlx *dest);
void			initialize_struct_values(t_mlx *mlx);
void			copy_height_width(t_mlx *mlx, t_mlx *temp);

/* utility2.c */
int				ft_height(char **characters);
int				ft_width(char **characters);
int				count_word(char const *str, char c);
void			print_data(t_mlx *mlx);

#endif
