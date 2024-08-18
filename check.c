/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:03:26 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/18 20:36:15 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int  is_rectangle(char **map, int row_count)
{
	int	i;
	int	first_row_length;

	if (row_count == 0)
		return (0);  // An empty map is not considered a rectangle
	first_row_length = strlen(map[0]);
	i = 1;
	while (i < row_count)
	{
		if (strlen(map[i]) != first_row_length)
			return (0);  // Found a row with a different length
		i++;
	}
	if (i == first_row_length)
		return (4); 
	return (1);  // All rows have the same length
}

int	four_walls(char **map, int row_count)
{
	int	first_row_length;
	int	last_row;
	int	i;

	first_row_length = strlen(map[0]);
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

int	member_validity(int c, int p, int e)
{
	if (c < 1)
		return (2);
	if (p != 1)
		return (3);
	if (e != 1)
		return (4);
	return (1);
}

int	members(char **map, int row_count, int col_count)
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

int	foreign_objects(char **map, int row_count, int col_count)
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
				return (0);
		}
	}
	return (1);
}
