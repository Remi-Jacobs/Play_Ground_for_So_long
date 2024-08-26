/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:35:11 by ojacobs           #+#    #+#             */
/*   Updated: 2024/08/18 12:43:17 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// int main() {
// 	char src[] = "Hello, World!";
// 	char dest[20];

// 	// Copy the first 5 characters of src to dest
// 	ft_strncpy(dest, src, 5);

// 	// Ensure the string is null-terminated (if needed)
// 	dest[5] = '\0';

// 	printf("Source: %s\n", src);
// 	printf("Destination: %s\n", dest);

// 	return 0;
// }
