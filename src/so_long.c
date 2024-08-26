/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:36:42 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/26 20:07:53 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invailid argument number\n", 2);
		return (1);
	}
	check_ber(argv[1]);
	game.map = count_rows_and_allocate(argv[1], &game.rows);
	if (!game.map)
	{
		ft_putstr_fd("failed to load\n", 2);
		return (1);
	}
	pre_load_map(argv[1], game.map);
	game.cols = ft_strlen(game.map[0]);
	if (error_check(game.map, game.rows, game.cols) == 0)
	{
		free_map_rows(game.map);
		return (2);
	}
	validate_map(&game);
	init_game(&game);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game_on_cross, &game);
	mlx_loop(game.mlx);
	return (0);
}
