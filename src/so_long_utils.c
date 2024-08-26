/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:21:31 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/26 12:43:15 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_game_on_cross(t_game *game)
{
	close_game(game);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_collectible);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->win = NULL;
	game->mlx = NULL;
	free_map(game);
	exit(0);
}

void	free_map_rows(char **rows)
{
	int	i;

	i = 0;
	while (rows[i])
	{
		free(rows[i]);
		i++;
	}
	free(rows);
}

void	validate_map(t_game *game)
{
	if (!is_map_valid(game))
	{
		ft_printf("Error: Not all collectibles or the exit are reachable.\n");
		free_map_rows(game->map);
		exit(EXIT_FAILURE);
	}
}
