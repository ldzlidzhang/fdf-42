/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:32:52 by lidzhang          #+#    #+#             */
/*   Updated: 2023/01/30 22:41:10 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	initiate_image(int fd, int height, char *argv)
{
	t_mlx	*mlx;
	char	**characters;
	int		**int_data;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		ft_exit("initiate_image error: Unable to malloc.\n\e[0m");
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, G_WIDTH, G_HEIGHT, argv);
	height = valid_map(fd, height, argv);
	characters = file_to_str(fd, height, argv);
	mlx->int_data = str_to_int(characters);
	mlx->map_height = height;
	mlx->map_width = ft_width(characters);
	get_struct_values(mlx);
	ft_render(mlx);
	mlx_hook(mlx->win_ptr, 2, 5, navigation_keys, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		height;

	fd = 0;
	height = 0;
	if (argc == 1)
		ft_exit(YELLOW"Usage: ./fdf resource/maps/test_maps\n\e[0m");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_no_file(argv[1]);
	initiate_image(fd, height, argv[1]);
	close(fd);
	return (0);
}
