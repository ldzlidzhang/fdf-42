/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:35:42 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/30 23:32:52 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	valid_map(int fd, int height, char *argv)
{
	int		ft_return;
	int		wcount;
	int		temp_wcount;
	char	*temp_line;

	initial_value(&temp_wcount, &wcount, &ft_return, &height);
	ft_return = get_next_line(fd, &temp_line);
	invalid_file(ft_return, argv);
	if (ft_return == 1)
	{
		wcount = word_count(temp_line, ' ');
		height++;
	}
	while (ft_return == 1)
	{
		temp_wcount = word_count(temp_line, ' ');
		if (temp_wcount != wcount)
			ft_exit(YELLOW"Error: Irregular number of elements in rows\n\e[0m");
		free(temp_line);
		ft_return = get_next_line(fd, &temp_line);
		height++;
	}
	close(fd);
	return (height);
}

void	initial_value(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

char	**file_to_str(int fd, int height, char *argv)
{
	int		i;
	int		width;
	char	**characters;
	char	*line;

	initial_value(&fd, &i, &width, &width);
	characters = (char **)malloc(sizeof(char *) * (height + 1));
	if (characters == NULL)
		return (NULL);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		width = ft_strlen(line);
		line[width] = '\0';
		characters[i] = ft_strdup(line);
		free(line);
		i++;
	}
	characters[i] = NULL;
	return (characters);
}

static int	*ft_2d_atoi(char *str)
{
	int		i;
	int		wordcount;
	int		*int_data;
	char	**words;

	i = 0;
	wordcount = word_count(str, ' ');
	words = ft_split(str, ' ');
	int_data = malloc(sizeof(int) * (wordcount));
	if (int_data == NULL)
		ft_exit("ft_2d_atoi() error: Unable to malloc.\n\e[0m");
	while (wordcount)
	{
		if (ft_isdigit(words[i][0]) == 1)
			int_data[i] = ft_atoi(words[i]);
		else if (words[i][0] == '-' && ft_isdigit(words[i][1]) == 1)
			int_data[i] = ft_atoi(words[i]);
		else
			ft_exit(YELLOW"Error: File has non integer values\n\e[0m");
		free(words[i]);
		i++;
		wordcount--;
	}
	free(words);
	return (int_data);
}

int	**str_to_int(char **characters)
{
	int	i;
	int	height;
	int	**int_data;

	i = 0;
	height = ft_height(characters);
	int_data = malloc(sizeof(int *) * (height));
	if (int_data == NULL)
		ft_exit("str_to_int error: Unable to allocate memory.\n\e[0m");
	while (height)
	{
		int_data[i] = ft_2d_atoi(characters[i]);
		i++;
		height--;
	}
	return (int_data);
}
