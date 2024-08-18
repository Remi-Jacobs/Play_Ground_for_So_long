
#include "../inc/so_long.h"


t_node *create_node(char *line) 
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node) return NULL;
	new_node->line = line;
	new_node->next = NULL;
	return new_node;
}

// char **con_to_str(int row_count, t_node *head)
// {
// 	char **rows;
// 	t_node *current;
// 	t_node *temp;
// 	int i;

// 	rows = malloc(row_count * sizeof(char *));
// 	if (!rows) 
// 	{
// 		perror("malloc");
// 		return NULL;
// 	}
// 	current = head;
// 	i = 0;
// 	while (i < row_count)
// 	{
// 		rows[i] = current->line;
// 		temp = current;
// 		current = current->next;
// 		free(temp); // Free the node, but keep the line
// 		i++;
// 	}
// 	return (rows);
// }



char **con_to_str(int row_count, t_node *head) {
    char **rows = malloc(row_count * sizeof(char *));
    if (!rows) {
        perror("malloc");
        return NULL;  // Return NULL instead of 1 for error handling
    }
    
    t_node *current = head;
    int i = 0;
    while (i < row_count) {
        rows[i] = current->line;
        t_node *temp = current;
        current = current->next;
        free(temp);  // Free the node, but keep the line
        i++;
    }
    return rows;
}

void pre_load_map(t_game *game, char **str, int *row_count_ptr, char ***new_str_ptr) {
    int fd;
    t_node *head = NULL;
    t_node *tail = NULL;
    char *line;
    int row_count = 0;
    char **new_str;

    fd = open(str[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while ((line = get_next_line(fd)) != NULL) {
        t_node *new_node = create_node(line);
        if (!new_node) {
            perror("malloc");
            close(fd);
            exit(EXIT_FAILURE);
        }
        if (tail) {
            tail->next = new_node;
        } else {
            head = new_node;  // First node becomes the head
        }
        tail = new_node;
        row_count++;
    }
    close(fd);  // Don't forget to close the file descriptor

    new_str = con_to_str(row_count, head);
    if (!new_str) {
        exit(EXIT_FAILURE);  // Exit if memory allocation fails
    }

    *row_count_ptr = row_count;  // Set the row count
    *new_str_ptr = new_str;      // Set the pointer to the 2D array
}



int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    t_game game;  // Your game-related structures if any
    int row_count = 0;
    char **rows = NULL;

    // Load the map (file) into a 2D array
    pre_load_map(&game, argv, &row_count, &rows);
	printf("row count is: %d\n", row_count);
    // Print the 2D array
    for (int i = 0; i < row_count; i++) {
        printf("Row %d: %s", i, rows[i]);
        free(rows[i]);  // Free each line after use
    }
    free(rows);  // Free the array of pointers

    return 0;
}