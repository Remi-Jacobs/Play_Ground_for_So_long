/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 06:46:52 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 06:06:18 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*bytestr1 = (unsigned char *)s1;
	const unsigned char	*bytestr2 = (unsigned char *)s2;

	while (n)
	{
		if (*bytestr1 != *bytestr2)
		{
			return (*bytestr1 - *bytestr2);
		}
		bytestr1++;
		bytestr2++;
		n--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	const char *s1 = "Hello, World!";
// 	const char *s2 = "Hello, Universe!";
// 	size_t n = 7;

// 	int result = ft_memcmp(s1, s2, n);
// 	printf("%d\n", result);
// }