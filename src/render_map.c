/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:16:25 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/26 12:32:40 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img_wall, x * 64, y * 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img_floor, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img_collectible, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img_exit, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img_player, x * 64, y * 64);
		game->player_x = x;
		game->player_y = y;
	}
}

void	render_row(t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < game->cols)
	{
		render_tile(game, x, y);
		x++;
	}
}

void	render_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->rows)
	{
		render_row(game, y);
		y++;
	}
}
