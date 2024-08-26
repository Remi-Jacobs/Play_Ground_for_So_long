/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:21:49 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 05:45:44 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytestr;

	bytestr = (unsigned char *)b;
	while (len != 0)
	{
		*bytestr = (unsigned char)c;
		len--;
		bytestr++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
// 	char buffer[10];

// 	// Fill the buffer with 'A' (ASCII value 65)
// 	ft_memset(buffer, 'A', sizeof(buffer));

// 	// Print the contents of the buffer
// 	for (int i = 0; i < sizeof(buffer); i++) {
// 		printf("%c ", buffer[i]);
// 	}

// 	return 0;
// }
