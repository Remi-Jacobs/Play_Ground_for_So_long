/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:36:00 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/26 20:35:29 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	member_validity(int c, int p, int e)
{
	int	result;

	result = 1;
	if (c < 1)
	{
		ft_putstr_fd("Error: Not enough collectibles\n", 2);
		result = 0;
	}
	if (p != 1)
	{
		ft_putstr_fd("Error: Invalid player number\n", 2);
		result = 0;
	}
	if (e != 1)
	{
		ft_putstr_fd("Error: Invalid exit\n", 2);
		result = 0;
	}
	return (result);
}

int	is_allowed_char(char c, char *allowed_chars)
{
	int	i;

	i = 0;
	while (allowed_chars[i] != '\0')
	{
		if (c == allowed_chars[i])
			return (1);
		i++;
	}
	return (0);
}

void	image_load_failed(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->win = NULL;
	game->mlx = NULL;
	free_map(game);
}
