/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:34:01 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/26 12:17:19 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_rectangle(char **map, int row_count)
{
	int		i;
	size_t	first_row_length;

	if (row_count == 0)
		return (0);
	first_row_length = ft_strlen(map[0]);
	i = 1;
	while (i < row_count)
	{
		if (ft_strlen(map[i]) != first_row_length)
			return (0);
		i++;
	}
	if (i == (int)first_row_length)
		return (0);
	return (1);
}

static int	four_walls(char **map, int row_count)
{
	int	first_row_length;
	int	last_row;
	int	i;

	first_row_length = ft_strlen(map[0]);
	last_row = row_count - 1;
	i = -1;
	while (++i < first_row_length)
	{
		if (map[0][i] != '1')
			return (0);
	}
	i = -1;
	while (++i < first_row_length)
	{
		if (map[last_row][i] != '1')
			return (0);
	}
	i = 0;
	while (++i < last_row)
	{
		if (map[i][0] != '1' || map[i][first_row_length - 1] != '1')
			return (0);
	}
	return (1);
}

static int	members(char **map, int row_count, int col_count)
{
	int	player;
	int	collectibles;
	int	exit;
	int	i;
	int	j;

	player = 0;
	collectibles = 0;
	exit = 0;
	i = -1;
	while (++i < row_count)
	{
		j = -1;
		while (++j < col_count)
		{
			if (map[i][j] == 'C')
				collectibles++;
			else if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
		}
	}
	return (member_validity(collectibles, player, exit));
}

static int	foreign_objects(char **map, int row_count, int col_count)
{
	int		i;
	int		j;
	char	*objects;

	objects = "10CPE";
	i = -1;
	while (++i < row_count)
	{
		j = -1;
		while (++j < col_count)
		{
			if (!is_allowed_char(map[i][j], objects))
			{
				ft_putstr_fd("Foreign object in map\n", 2);
				return (0);
			}
		}
	}
	return (1);
}

int	error_check(char **map, int row_count, int col_count)
{
	if (is_rectangle(map, row_count) == 0)
	{
		ft_putstr_fd("Error: Map is not rectangular\n", 2);
		return (0);
	}
	if (four_walls(map, row_count) == 0)
	{
		ft_putstr_fd("Error: The wall is breached\n", 2);
		return (0);
	}
	if (members(map, row_count, col_count) == 0)
		return (0);
	if (foreign_objects(map, row_count, col_count) == 0)
		return (0);
	return (1);
}
