/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:03:26 by lidzhang          #+#    #+#             */
/*   Updated: 2023/02/01 13:29:14 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_exit_no_file(char *argv)
{
	ft_putstr_fd(YELLOW"Error: "CYAN, 1);
	ft_putstr_fd(argv, 1);
	ft_putstr_fd("\e[0m", 1);
	fdf_exit(YELLOW" file does not exist\n\e[0m");
}

void	fdf_exit_dir(char *str)
{
	ft_putstr_fd(YELLOW"Error: "CYAN, 1);
	perror(str);
	ft_putstr_fd("\e[0m", 1);
	exit(EXIT_FAILURE);
}

void	fdf_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	fdf_exit_success(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_SUCCESS);
}

void	invalid_file_message(int ft_return, char *argv)
{
	if (ft_return == 0)
		fdf_exit(YELLOW"Error: File is empty\n\e[0m");
	if (ft_return == -1)
		fdf_exit_dir(argv);
}
