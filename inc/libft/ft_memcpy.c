/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:35:54 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 12:49:00 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*bytedest;
	unsigned char	*bytesrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	bytedest = (unsigned char *)dst;
	bytesrc = (unsigned char *)src;
	while (n != 0)
	{
		*bytedest = *bytesrc;
		n--;
		bytedest++;
		bytesrc++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
// 	char src[] = "Hello, World!";
// 	char dst[50] = "Do not panic here is the wayyyyyyyyyyyyyyyy";

// 	// Copy the content of 'src' to 'dst'
// 	memcpy(dst, src, 5);

// 	// Print the result
// 	printf("Copied String: %s\n", dst);

// 	return 0;
// }