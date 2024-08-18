/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:33:39 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 05:57:59 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = ft_strlen(dst);
	destlen = i;
	srclen = ft_strlen(src);
	if (size <= destlen)
	{
		return (srclen + size);
	}
	while (*src != '\0' && i < size - 1)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (destlen + srclen);
}

// #include <stdio.h>

// // Prototype of the function

// int main() {
// 	char destination[200] = "Hellheyasuckazo";
// 	const char *source = "Worlfsbjhsfaghg";
// 	size_t result = ft_strlcat(destination, source, sizeof(destination));
// 	printf("Concatenated string: %s\n", destination);
// 	printf("Total length: %zu\n", result);
// 	return 0;
// }