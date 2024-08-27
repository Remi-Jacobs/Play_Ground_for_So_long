/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_load_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:32:25 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/27 14:12:01 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_ber(const char *filename)
{
	const char	*extension;
	const char	*file_extension;
	size_t		len_filename;
	size_t		len_extension;

	extension = ".ber";
	len_extension = ft_strlen(extension);
	len_filename = ft_strlen(filename);
	if (len_filename < len_extension)
		return (0);
	file_extension = filename + len_filename - len_extension;
	if (ft_strncmp(file_extension, extension, len_extension) == 0)
		return (1);
	else
	{
		ft_printf("Error: Invalid file extension. Please use a .ber file\n");
		exit(EXIT_FAILURE);
	}
}

char	**count_rows_and_allocate(const char *filename, int *row_count_ptr)
{
	int		fd;
	char	*line;
	int		row_count;
	char	**rows;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	row_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		row_count++;
	}
	close(fd);
	if (row_count == 0)
		return (ft_printf("Error: Empty file\n"), NULL);
	rows = ft_calloc(row_count + 1, sizeof(char *));
	if (!rows)
		return (perror("ft_calloc"), NULL);
	*row_count_ptr = row_count;
	return (rows);
}

void	pre_load_map(const char *filename, char **rows)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return ;
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
