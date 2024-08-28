/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:16:38 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/28 15:23:58 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	update_exit_image(t_game *game)
{
	int	i;

	if (game->collected == game->total_collectibles)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx, \
	"./Images/Gate_Opened.xpm", &game->map_width, &game->map_height);
	}
	if (game->collected >= (game->total_collectibles / 2))
	{
		mlx_destroy_image(game->mlx, game->img_wall);
		game->img_wall = mlx_xpm_file_to_image(game->mlx, \
		"./Images/Tower_Red.xpm", &game->map_width, &game->map_height);
	}
	i = game->total_collectibles;
	if (game->collected >= ((i / 2) + (i / 4)))
	{
		mlx_destroy_image(game->mlx, game->img_floor);
		game->img_floor = mlx_xpm_file_to_image(game->mlx,\
		"./Images/Rainbow.xpm", &game->map_width, &game->map_height);
	}
}

void handle_movement(t_game *game, int *count, int keycode, int *new_x, int *new_y)
{
	char next_tile;

	if (keycode == KEY_A || keycode == KEY_D || \
	keycode == KEY_S || keycode == KEY_W)
	{
		if (keycode == KEY_W)
			next_tile = game->map[(*new_y) - 1][*new_x],(*new_y)--;
		
		else if (keycode == KEY_S)
			next_tile = game->map[(*new_y) + 1][(*new_x)],(*new_y)++;
		else if (keycode == KEY_A)
			next_tile = game->map[(*new_y)][(*new_x) - 1],(*new_x)--;
		else if (keycode == KEY_D)
			next_tile = game->map[(*new_y)][(*new_x) + 1],(*new_x)++;
		if (next_tile == '0' || next_tile == 'E' || next_tile == 'C')
		{
			(*count)++;
			ft_printf("Total moves = %d\n", *count);
		}
	}
}

void	update_position(t_game *game, int new_x, int new_y)
{
	char	next_tile;

	next_tile = game->map[new_y][new_x];
	if (next_tile != '1')
	{
		if (game->map[game->player_y][game->player_x] == 'E')
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		if (game->map[new_y][new_x] != 'E')
			game->map[new_y][new_x] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
	}
}

void	check_tile(t_game *game, int new_x, int new_y)
{
	char	next_tile;

	next_tile = game->map[new_y][new_x];
	if (next_tile != '1')
	{
		if (next_tile == 'C')
		{
			game->collected++;
			game->map[new_y][new_x] = '0';
		}
		else if (next_tile == 'E' && game->collected \
		== game->total_collectibles)
		{
			ft_putstr_fd("You win!\n", 1);
			close_game(game);
		}
	}
}

int	key_hook(int keycode, t_game *game)
{
	static int move_count;
	int new_x;
	int new_y;
	static int check;

	if (check == 0)
		move_count = -1;
	check++;
	new_x = game->player_x;
	new_y = game->player_y;
	handle_movement(game, &move_count, keycode, &new_x, &new_y);
	if (keycode == KEY_ESC)
	{
		close_game(game);
	}
	check_tile(game, new_x, new_y);
	update_position(game, new_x, new_y);
	update_exit_image(game);
	render_map(game);
	return (0);
}
