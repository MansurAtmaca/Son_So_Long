/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansurcanatmaca <mansurcanatmaca@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:18:01 by matmaca           #+#    #+#             */
/*   Updated: 2024/04/15 22:42:05 by mansurcanat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_char
{
	void	*player;
	int		ply_x;
	int		ply_y;
}	t_char;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}	t_map;

typedef struct s_win
{
	t_map	map;
	t_map	copy_map;
	t_char	player;
	void	*mlx_win;
	void	*mlx_ptr;
	int		height;
	int		width;
	void	*background;
	void	*wall;
	void	*exit;
	void	*coin;
	int		collected_coin;
	int		move_count;
	int		player_count;
	int		coin_count;
	int		exit_count;
	int		path_exit;
	int		path_coin;
	int		px;
	int		py;
}	t_win;

char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);


//map_funcs
void	get_map(t_win *win, char *path);
void	add_images(t_win *win);
void	put_images_right_places(t_win *win, char c, int x, int y);
void	init_values(t_win *win);

//free_funcs
void	ft_free(t_win *win, int a);
int		close_game(void *param);
void	close_images(t_win *win);

//check_funcs
void	check_file_path(char *file_name);
void	check_file_status(char *file_name);
void	empty_check(char *line);

//controls
void	wall_control(t_win *win, int height, int width);
void	value_control(t_win *win);
void	check_wall_access(t_win *win);
void	is_accessible(t_win *win, int y, int x);
void	copy_map(t_win *win, t_map *map);
void	rec_control(t_win *win);

#endif
