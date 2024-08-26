/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:58:22 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/21 19:59:33 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	i = 0;
	while (*haystack != '\0' && len > 0)
	{
		while (needle[i] != '\0' && haystack[i] != '\0'
			&& haystack[i] == needle[i])
		{
			i++;
		}
		if (needle[i] == '\0' && i <= len)
		{
			return ((char *)haystack);
		}
		haystack++;
		len--;
		i = 0;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	const char *big = "There once was a tree by the merry good sea";
// 	const char *lil = "tree";
// 	size_t len = 0;
// 	char *result = ft_strnstr(big, lil, len);
// 	if (result != NULL) {
// 		printf("Substring found: %s\n", result);
// 	} else {
// 		printf("Substring not found within the first %zu characters.\n", len);
// 	}
// 	return 0;
// }