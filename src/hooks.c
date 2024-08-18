/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:16:38 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/17 18:41:18 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


int key_hook(int keycode, t_game *game)
{
    if (keycode == 119) // W key
        move_player(game, 0, -1);
    else if (keycode == 115) // S key
        move_player(game, 0, 1);
    else if (keycode == 97) // A key
        move_player(game, -1, 0);
    else if (keycode == 100) // D key
        move_player(game, 1, 0);
    else if (keycode == 65307) // ESC key
        close_game(game);
    return (0);
}

void move_player(t_game *game, int x_offset, int y_offset)
{
    // Calculate the new player position
    int new_x = game->player_x + x_offset;
    int new_y = game->player_y + y_offset;

    // Bounds checking to prevent out-of-bounds access
    if (new_x < 0 || new_x >= game->map_width || new_y < 0 || new_y >= game->map_height)
    {
        return;  // Do nothing if the move is out of bounds
    }

    // Check the content of the map at the new position
    char next_tile = game->map[new_y][new_x];

    // Handle different types of tiles
    if (next_tile != '1') // '1' represents a wall
    {
        if (next_tile == 'C') // 'C' represents a collectible
        {
            game->collected++;
        }
        else if (next_tile == 'E' && game->collected == game->collectibles) // 'E' represents the exit
        {
            close_game(game);
            return;
        }

        // Update the player's position on the map
        game->map[game->player_y][game->player_x] = '0'; // '0' represents an empty space
        game->player_x = new_x;
        game->player_y = new_y;
        game->map[game->player_y][game->player_x] = 'P'; // 'P' represents the player

        // Render the updated map
        render_map(game);
    }
}

int close_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    free_map(game);
    exit(0);
}
