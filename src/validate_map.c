/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:07:42 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/26 14:06:01 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	dfs(t_game *game, int x, int y, bool **visited)
{
	if (x < 0 || y < 0 || x >= game->cols || y >= game->rows \
		|| game->map[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = true;
	if (game->map[y][x] == 'C')
		game->collected++;
	else if (game->map[y][x] == 'E')
		game->exit_found = (true);
	dfs(game, x + 1, y, visited);
	dfs(game, x - 1, y, visited);
	dfs(game, x, y + 1, visited);
	dfs(game, x, y - 1, visited);
}

bool	find_player_start(t_game *game, int *start_x, int *start_y)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

bool	**initialize_visited(t_game *game)
{
	bool	**visited;
	int		i;

	visited = (bool **)malloc(game->rows * sizeof(bool *));
	i = 0;
	while (i < game->rows)
	{
		visited[i] = (bool *)calloc(game->cols, sizeof(bool));
		i++;
	}
	return (visited);
}

void	innit_collectibles(t_game *game)
{
	int	i;
	int	k;
	int	c;

	i = 0;
	c = 0;
	game->collected = 0;
	game->exit_found = false;
	while (i < game->rows)
	{
		k = 0;
		while (k < game->cols)
		{
			if (game->map[i][k] == 'C')
				c++;
			k++;
		}
		i++;
	}
	game->total_collectibles = c;
}

bool	is_map_valid(t_game *game)
{
	int		start_x;
	int		start_y;
	int		i;
	bool	**visited;

	innit_collectibles(game);
	start_x = -1;
	start_y = -1;
	if (!find_player_start(game, &start_x, &start_y))
	{
		printf("Player start position not found.\n");
		return (false);
	}
	visited = initialize_visited(game);
	dfs(game, start_x, start_y, visited);
	i = 0;
	while (i < game->rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	return (game->collected == game->total_collectibles && game->exit_found);
}
