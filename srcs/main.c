/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:32:52 by lidzhang          #+#    #+#             */
/*   Updated: 2023/02/01 13:53:29 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	solve_driver(int fd, int height, char *argv)
{
	t_mlx	*mlx;
	char	**characters;
	int		**int_data;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		fdf_exit("error: Unable to malloc.\n\e[0m");
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, P_WIDTH, P_HEIGHT, argv);
	height = map_valid(fd, height, argv);
	characters = file_to_str(fd, height, argv);
	mlx->int_data = str_to_int(characters);
	mlx->map_height = height;
	mlx->map_width = ft_width(characters);
	initialize_struct_values(mlx);
	ft_render(mlx);
	mlx_hook(mlx->win_ptr, 2, 5, program_keys, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	height;

	fd = 0;
	height = 0;
	if (argc == 1)
		fdf_exit(YELLOW"Usage: ./fdf resources/maps/test_maps\n\e[0m");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fdf_exit_no_file(argv[1]);
	solve_driver(fd, height, argv[1]);
	close(fd);
	return (0);
}
