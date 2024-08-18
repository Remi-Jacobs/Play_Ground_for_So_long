
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the map is a rectangle
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

int main() {
	// Example map
	char *example_map[] = {
		"11111",
		"1C001",
		"10001",
		"10P01",
		"1C0E1",
		"11111"
	};

	int row_count = sizeof(example_map) / sizeof(example_map[0]);
	 int col_count = strlen(example_map[0]);

	int rect_result = is_rectangle(example_map, row_count);

	if (rect_result == 1) {
		printf("The map is a rectangle.\n");
	} else if (rect_result == 4) {
		printf("This is a square bro, what are you doing?\n");
	} else {
		printf("The map is not a rectangle.\n");
	}

	if (four_walls(example_map, row_count) == 1) {
		printf("The map has four walls.\n");
	} else {
		printf("The wall has been breached.\n");
	}
	int mem_result = members(example_map, row_count, col_count);
	if (mem_result == 1) {
		printf("The map has all required members.\n");
	} else if (mem_result == 2) {
		printf("The map does not have enough collictibles?\n");
	}  else if (mem_result == 3) {
		printf("invalid player number?\n");
	} 
	 else if (mem_result == 4) {
		printf("invalid exit?\n");
	}
	if (foreign_objects(example_map, row_count, col_count)) {
        printf("The map contains only allowed objects.\n");
    } else {
        printf("The map contains foreign objects.\n");
    }
	// Print and free the map
	int i = 0;
	while (i < row_count) {
		printf("Row %d: %s\n", i, example_map[i]);
		// If these rows were dynamically allocated, you'd free them here:
		// free(example_map[i]);
		i++;
	}

	// If example_map was dynamically allocated:
	// free(example_map);

	return 0;
}
