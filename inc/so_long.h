/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:56 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/18 13:56:28 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// # include <mlx.h>
# include "../mlx/minilibx-linux/mlx.h"
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <sys/time.h> 
# include "./libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_player;
	void    *img_wall;
	void    *img_collectible;
	void    *img_exit;
	void    *img_floor;
	int     map_width;
	int     map_height;
	char    **map;
	int     player_x;
	int     player_y;
	int     collectibles;
	int     collected;
}	t_game;

typedef struct s_node 
{
	char *line;
	struct s_node *next;
} t_node;

void    init_game(t_game *game);
void    load_map(t_game *game, const char *map_path);
void    render_map(t_game *game);
void    move_player(t_game *game, int x, int y);
int     key_hook(int keycode, t_game *game);
int     close_game(t_game *game);
void    free_map(t_game *game);

# define TILE_SIZE 32

#endif