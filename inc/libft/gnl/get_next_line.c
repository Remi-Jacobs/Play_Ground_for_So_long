/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:46:51 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/25 16:04:02 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_bucket(int fd, char *bucket)
{
	int		fd_read;
	char	*bailer;

	bailer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!bailer)
		return (NULL);
	fd_read = 1;
	while (!ft_gchr(bucket, '\n') && fd_read != 0)
	{
		fd_read = read(fd, bailer, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(bailer);
			free(bucket);
			return (NULL);
		}
		bailer[fd_read] = '\0';
		bucket = ft_m_strjoin(bucket, bailer);
	}
	free(bailer);
	return (bucket);
}

char	*ft_get_line(char *bucket)
{
	char	*line;
	int		c;

	c = 0;
	if (!bucket[c])
		return (NULL);
	while (bucket[c] && bucket[c] != '\n')
		c++;
	line = malloc((c + 2) * sizeof(char));
	if (!line)
		return (NULL);
	c = 0;
	while (bucket[c] && bucket[c] != '\n')
	{
		line[c] = bucket[c];
		c++;
	}
	if (bucket[c] == '\n')
	{
		line[c] = bucket[c];
		c++;
	}
	line[c] = '\0';
	return (line);
}

char	*ft_new_bucket(char *bucket)
{
	char	*new_bucket;
	int		c;
	int		c2;

	c = 0;
	while (bucket[c] && bucket[c] != '\n')
		c++;
	if (!bucket[c])
	{
		free(bucket);
		return (NULL);
	}
	new_bucket = malloc((ft_glen(bucket) - c) * sizeof(char) + 2);
	if (!new_bucket)
		return (NULL);
	c++;
	c2 = 0;
	while (bucket[c])
		new_bucket[c2++] = bucket[c++];
	new_bucket[c2] = '\0';
	free(bucket);
	return (new_bucket);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bucket[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bucket[fd] = ft_read_to_bucket(fd, bucket[fd]);
	if (!bucket[fd])
		return (NULL);
	line = ft_get_line(bucket[fd]);
	bucket[fd] = ft_new_bucket(bucket[fd]);
	return (line);
}

// int main() 
// {
//     int fd = open("signature.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Error opening file");
//         return -1;
//     }

//     char *nextline;
// 	// nextline = get_next_line(fd);
// 	//  printf("%s\n", nextline);
//     //     free(nextline);
//     while ((nextline = get_next_line(fd)) != NULL) {
//         printf("%s", nextline);
//         free(nextline); // Free memory allocated for each line
//     }
// 	// while (nextline != NULL)
// 	// {
// 	// 	nextline = get_next_line(fd);
//     //     printf("%s\n", nextline);
//     //     free(nextline); // Free memory allocated for each line
//     // }

//     close(fd);
//     return 0;
// }