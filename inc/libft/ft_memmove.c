/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:16:20 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 05:54:57 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*bytedest;
	unsigned char	*bytesrc;

	bytedest = (unsigned char *)dst;
	bytesrc = (unsigned char *)src;
	if (bytedest < bytesrc)
		while (len--)
			*bytedest++ = *bytesrc++;
	else if (bytedest > bytesrc)
		while (len--)
			*(bytedest + len) = *(bytesrc + len);
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
// 	char buffer[20] = "Hello, World!";
// 	char simp[] = "Rock";

// 	// Move the "World!" part to the beginning of the buffer
// 	ft_memmove(buffer + 13, simp, 4);

// 	// Print the result
// 	printf("Modified String: %s\n", buffer);

// 	return 0;
// }
