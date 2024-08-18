/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:53:59 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 05:56:44 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (*src != '\0' && i < (size - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (len);
}

// #include <stdio.h>
// int main() {
// 	char dst[15];
// 	const char *source = "This is a long string";

// 	size_t length = ft_strlcpy(dst, source, sizeof(dst));

// 	printf("Copied string: %s\n", dst);
// 	printf("Length of the source string: %zu\n", length);

// 	return 0;
// }