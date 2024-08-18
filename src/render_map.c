/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:16:25 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/17 18:30:34 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void render_map(t_game *game)
{
    int x, y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'C')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
                game->collectibles++;
            }
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}