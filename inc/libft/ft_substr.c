/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:45:25 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/21 12:39:36 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	rest;
	size_t	slen;

	rest = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start < slen)
		rest = slen - start;
	else
	{
		sub_str = (char *)malloc(1 * sizeof(char));
		*sub_str = 0;
		return (sub_str);
	}
	if (rest > len)
		rest = len;
	sub_str = (char *)malloc ((rest + 1) * sizeof(char));
	if (sub_str == (NULL))
		return (NULL);
	ft_strlcpy(sub_str, s + start, rest + 1);
	return (sub_str);
}

// #include <stdio.h>
// int main ()
// {
// 	char s[] = "Oluremilekun";
// 	char *str = ft_substr(s,41,4);

// 	printf("%s\n", str);

// 	free(str);

// 	return 0;
// }