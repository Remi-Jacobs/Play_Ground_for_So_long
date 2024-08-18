/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 05:48:57 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 06:05:05 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*bytestr;

	bytestr = (unsigned char *)s;
	while (n)
	{
		if (*bytestr == (unsigned char)c)
		{
			return ((void *)bytestr);
		}
		bytestr++;
		n--;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	char *bruh = "We are the world";
// 	char f = 't';
// 	void * result = ft_memchr(bruh, f, 15);
// 		printf("Copied String: %s\n", result);

// 	return 0;
// }