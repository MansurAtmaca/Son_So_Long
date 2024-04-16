/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:12:06 by matmaca           #+#    #+#             */
/*   Updated: 2024/04/16 10:43:05 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "../printf/ft_printf.h"

void	check_file_path(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (file_name[i - 1] != 'r' || file_name[i - 2] != 'e'
		|| file_name[i - 3] != 'b' || file_name[i - 4] != '.')
	{
		ft_printf("Wrong path name!!\n");
		exit(1);
	}
}

void	empty_check(char *line)
{
	if (*line == '\n')
	{
		ft_printf("Empty Line in Map\n");
		free(line);
		exit(1);
	}
}

void	init_values(t_win *win)
{
	win->player_count = 0;
	win->move_count = 0;
	win->coin_count = 0;
	win->collected_coin = 0;
	win->path_coin = 0;
	win->path_exit = 0;
	win->exit_count = 0;
}
