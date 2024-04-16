/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:14:06 by matmaca           #+#    #+#             */
/*   Updated: 2024/04/16 10:09:40 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../printf/ft_printf.h"

void	wall_control(t_win *win, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (win->map.map[i])
	{
		j = 0;
		while (win->map.map[i][j])
		{
			if (win->map.map[0][j] != '1' || win->map.map[height - 1][j] != '1')
			{
				ft_printf("Wall Error!\n");
				ft_free(win, 1);
			}
			else if (win->map.map[i][0] != '1' ||
				win->map.map[i][width - 1] != '1')
			{
				ft_printf("Wall Error!\n");
				ft_free(win, 1);
			}
			j++;
		}
		i++;
	}
}

void	check_errors(t_win *win)
{
	if (win->player_count != 1)
	{
		ft_printf("Player Error!\n");
		ft_free(win, 1);
	}
	if (win->coin_count < 1)
	{
		ft_printf("Coin Error!\n");
		ft_free(win, 1);
	}
	if (win->exit_count != 1)
	{
		ft_printf("Exit Error!\n");
		ft_free(win, 1);
	}
}

void	check_dif_char(t_win *win, int i, int j)
{
	if (win->map.map[i][j] != 'E' && win->map.map[i][j] !=
		'C' && win->map.map[i][j] != '1' &&
			win->map.map[i][j] != '0' && win->map.map[i][j] != 'P')
	{
		ft_printf("Unidentified character on map\n");
		ft_free(win, 1);
	}
}

void	value_control(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map.map[i])
	{
		j = 0;
		while (win->map.map[i][j])
		{
			if (win->map.map[i][j] == 'P')
			{
				win->player_count++;
				win->px = j;
				win->py = i;
			}
			else if (win->map.map[i][j] == 'C')
				win->coin_count++;
			else if (win->map.map[i][j] == 'E')
				win->exit_count++;
			check_dif_char(win, i, j);
			j++;
		}
		i++;
	}
	check_errors(win);
}
