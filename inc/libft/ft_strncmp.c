/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:10:24 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 06:03:36 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return ((unsigned char )*s1 - (unsigned char )*s2);
	}
}

// #include <stdio.h>
// int main() {
// 	// Example usage
// 	const char *string1 = "Hello";
// 	const char *string2 = "Hell";

// 	size_t n = 4;

// 	int result = ft_strncmp(string1, string2, n);

// 	if (result == 0) {
// 		printf("The first %lu characters are equal\n", n);
// 	} else if (result < 0) {
// 		printf("The first %lu charactString 2\n", n);
// 	} else {
// 		printf("The first %lu charactersthan String 2\n", n);
// 	}

// 	return 0;
// }
