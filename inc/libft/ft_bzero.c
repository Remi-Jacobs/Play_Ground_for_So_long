/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:09:39 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 05:50:41 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*bytestr;

	bytestr = (unsigned char *)s;
	while (n > 0)
	{
		*bytestr = 0;
		n--;
		bytestr++;
	}
}

// #include <stdio.h>
// #include <strings.h>

// int main() {
//      char buffer[15] = "Holla maaa";

//     ft_bzero(buffer, 8);

//     for (int i = 0; i < sizeof(buffer); i++) {
//         printf("%d ", buffer[i]);
//     }

//     return 0;
// }