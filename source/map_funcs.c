/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:26:16 by matmaca           #+#    #+#             */
/*   Updated: 2024/04/16 10:55:12 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../printf/ft_printf.h"
#include <fcntl.h>
#include <unistd.h>
#include "../minilibx/mlx.h"

char	*strappend(char **str, char *str2)
{
	char	*old;

	old = NULL;
	if (*str == NULL)
		*str = ft_strdup(str2);
	else
	{
		old = *str;
		*str = ft_strjoin(old, str2);
	}
	if (old)
		free(old);
	return (0);
}

char	*read_map(char *path)
{
	int		fd;
	char	*line;
	char	*ret;

	ret = NULL;
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File not opened!!\n");
		exit(1);
	}
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		empty_check(line);
		strappend(&ret, line);
	}
	free(line);
	close(fd);
	return (ret);
}

void	create_image(t_win *win)
{
	int	x;
	int	y;

	win->background = mlx_xpm_file_to_image(win->mlx_ptr,
			"./images/background.xpm", &x, &y);
	win->wall = mlx_xpm_file_to_image(win->mlx_ptr,
			"./images/wall.xpm", &x, &y);
	win->player.player = mlx_xpm_file_to_image(win->mlx_ptr,
			"./images/player.xpm", &x, &y);
	win->exit = mlx_xpm_file_to_image(win->mlx_ptr,
			"./images/exit.xpm", &x, &y);
	win->coin = mlx_xpm_file_to_image(win->mlx_ptr,
			"./images/coin.xpm", &x, &y);
	if (win->background == NULL || win->wall == NULL || win->exit == NULL
		|| win->player.player == NULL || win->coin == NULL)
	{
		ft_printf("Wrong image path!\n");
		close_game(win);
	}
}

void	add_images(t_win *win)
{
	win->height = win->map.height * 64;
	win->width = win->map.width * 64;
	win->player.ply_x = 0;
	win->player.ply_y = 0;
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		ft_free(win, 1);
	win->mlx_win = mlx_new_window(win->mlx_ptr, win->width, win->height,
			"Adventures of Gandalf");
	if (win->mlx_win == NULL)
		ft_free(win, 1);
	create_image(win);
}

void	get_map(t_win *win, char *path)
{
	t_map	the_map;
	char	*map;

	the_map.height = 0;
	map = read_map(path);
	if (map == NULL)
	{
		ft_printf("Map is empty!\n");
		exit(1);
	}
	the_map.map = ft_split(map, '\n');
	free(map);
	if (!the_map.map)
		exit (1);
	the_map.width = ft_strlen(the_map.map[0]);
	while (the_map.map[the_map.height] != NULL)
		the_map.height++;
	win->map = the_map;
	copy_map(win, &the_map);
	rec_control(win);
	wall_control(win, the_map.height, the_map.width);
	value_control(win);
	is_accessible(win, win->px, win->py);
	check_wall_access(win);
}
