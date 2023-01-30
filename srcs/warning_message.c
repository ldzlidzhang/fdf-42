/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:03:26 by lidzhang          #+#    #+#             */
/*   Updated: 2023/01/30 22:49:52 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* ESC terminates program*/
void	exit_succuess(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_SUCCESS);
}

/*Exit message*/
void	ft_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

/*Only file path*/
void	ft_exit_dir(char *str)
{
	ft_putstr_fd(YELLOW"Error: "CYAN, 1);
	perror(str);
	ft_putstr_fd("\e[0m", 1);
	exit(EXIT_FAILURE);
}

/*Empty file*/
void	invalid_file(int return_value, char *argv)
{
	if (return_value == 0)
		ft_exit(YELLOW"Error: File is empty\n\e[0m");
	if (return_value == -1)
		ft_exit_dir(argv);
}

void	exit_no_file(char *argv)
{
	ft_putstr_fd(YELLOW"Error: "CYAN, 1);
	ft_putstr_fd(argv, 1);
	ft_exit(YELLOW" file does not exist\n\e[0m");
}
