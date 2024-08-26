/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:44:48 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 06:02:05 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != ((char)c))
	{
		s = s + 1;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	else
	{
		return (NULL);
	}
}

// int main() 
// {
//     const char *testString = "Hello, World!";
//     int searchChar = 'r';
//
//     char *result = ft_strchr(testString, searchChar);
//
//     if (result != 0) {
//         printf("Character '%c' found 
//     } else {
//         printf("Character '%c' not foun
//d in the string.\n", (char)searchChar);
//     }
//
//     return 0;
// }