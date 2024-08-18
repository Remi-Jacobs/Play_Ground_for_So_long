/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:15:53 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/18 16:25:43 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->img_player = mlx_xpm_file_to_image(game->mlx, "Mage.xpm", &game->map_width, &game->map_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "GoldMine_Active.xpm", &game->map_width, &game->map_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "Mushroom.xpm", &game->map_width, &game->map_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "Bridge_All.xpm", &game->map_width, &game->map_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "Water.xpm", &game->map_width, &game->map_height);
	game->collectibles = 0;
	game->collected = 0;
}

t_node *create_node(char *line) 
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node) return NULL;
	new_node->line = line;
	new_node->next = NULL;
	return new_node;
}

char **con_to_str(int row_count, t_node *head)
{
	char **rows;
	t_node *current;
	t_node *temp;
	int i;

	rows = malloc(row_count * sizeof(char *));
	if (!rows) 
	{
		perror("malloc");
		return 1;
	}
	current = head;
	i = 0;
	while (i < row_count)
	{
		rows[i] = current->line;
		temp = current;
		current = current->next;
		free(temp); // Free the node, but keep the line
		i++;
	}
	return (rows);
}

void pre_load_map(t_game * game, char **str)
{
	int fd;
	t_node *head;
	t_node *tail;
	char *line;
	int row_count;
	char **new_str;

	fd = open(str[1], O_RDONLY);
	if (fd < 0) 
	{
		perror("open");
		exit (EXIT_FAILURE);
	}
	head = NULL;
	tail = NULL;
	row_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		t_node *new_node = create_node(line);
		if (!new_node) 
		{
			perror("malloc");
			close(fd);
			exit (EXIT_FAILURE);
		}
		if (tail)
		{
			tail->next = new_node;
		} 
		else 
			{
				head = new_node; // First node becomes the head
			}
		tail = new_node;
		row_count++;
	}
	new_str = con_to_str(row_count, head);
}

void load_map(t_game *game, const char *map_path)
{
	int fd;
	char *line;
	int y;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nFailed to open map file");
		exit(EXIT_FAILURE);
	}

	// Count the number of lines in the map to determine map height
	game->map_height = 0;
	game->map_width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (game->map_width == 0)
			game->map_width = ft_strlen(line) - 1; // -1 to ignore newline at the end
		game->map_height++;
		free(line);
	}
	close(fd);

	// Allocate memory for the map
	game->map = malloc(sizeof(char *) * game->map_height);
	if (!game->map)
	{
		perror("Error\nMemory allocation failed");
		exit(EXIT_FAILURE);
	}

	// Read the map again and store the lines
	fd = open(map_path, O_RDONLY);
	y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[y] = malloc(sizeof(char) * (game->map_width + 1));
		if (!game->map[y])
		{
			perror("Error\nMemory allocation failed");
			exit(EXIT_FAILURE);
		}
		strncpy(game->map[y], line, game->map_width);
		game->map[y][game->map_width] = '\0'; // Null-terminate the string
		free(line);
		y++;
	}
	close(fd);
}

// void load_map(t_game *game, const char *map_path)
// {
//     int fd = open(map_path, O_RDONLY);
//     char *line;
//     int y = 0;

//     while ((line = get_next_line(fd)))
//     {
//         game->map[y++] = line;
//         game->map_width = ft_strlen(line) - 1;
//     }
//     game->map_height = y;
//     close(fd);
// }

void free_map(t_game *game)
{
	int i = 0;

	while (i < game->map_height)
		free(game->map[i++]);
	free(game->map);
}
