/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:56 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/26 20:09:19 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <sys/time.h> 
# include "./libft/libft.h"
// # include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_floor;
	int		map_width;
	int		map_height;
	char	**map;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		rows;
	int		cols;
	int		total_collectibles;
	bool	exit_found;
}	t_game;

void	init_game(t_game *game);
void	load_map(t_game *game, const char *map_path);
void	render_map(t_game *game);
void	move_player(t_game *game, int x, int y);
int		key_hook(int keycode, t_game *game);
int		close_game(t_game *game);
int		close_game_on_cross(t_game *game);
void	free_map(t_game *game);
void	free_map_rows(char **rows);
void	innit_collectibles(t_game *game);
//Load map
int		check_ber(const char *filename);
char	**count_rows_and_allocate(const char *filename, int *row_count_ptr);
void	pre_load_map(const char *filename, char **rows);
int		error_check(char **map, int row_count, int col_count);
bool	is_map_valid(t_game *game);
void	validate_map(t_game *game);

//error check utils
int		member_validity(int c, int p, int e);
int		is_allowed_char(char c, char *allowed_chars);
void	image_load_failed(t_game *game);

#endif