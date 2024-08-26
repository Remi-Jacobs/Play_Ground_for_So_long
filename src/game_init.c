/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:15:53 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/26 17:41:12 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_images(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
	"./Images/Mage.xpm", &game->map_width, &game->map_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
	"./Images/Tower_Blue.xpm", &game->map_width, &game->map_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, \
	"./Images/Mushroom.xpm", &game->map_width, &game->map_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
	"./Images/Gate_Closed.xpm", &game->map_width, &game->map_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
	"./Images/Black.xpm", &game->map_width, &game->map_height);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: Failed to initialize MLX\n", 2);
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, \
	game->cols * 64, game->rows * 64, "So Long");
	if (!game->win)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		exit(EXIT_FAILURE);
	}
	innit_collectibles(game);
	init_images(game);
	if (!game->img_player || !game->img_wall || \
	!game->img_collectible || !game->img_exit || !game->img_floor)
	{
		ft_putstr_fd("Error: Failed to load one or more images\n", 2);
		image_load_failed(game);
		exit(EXIT_FAILURE);
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
		free(game->map[i++]);
	free(game->map);
}
