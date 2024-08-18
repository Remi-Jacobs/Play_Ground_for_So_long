/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:21:43 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 01:00:06 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last_occurrence);
}

// int main() 
// {
// 	const char *testString = "Hellor, Wold!r";
// 	int searchChar = 'r';

// 	char *result = ft_strrchr(testString, searchChar);

// 	if (result != 0) {
// 		printf("Character '%c' found %s\n", (char)searchChar, result);
// 	} 
// 	// else {
// 	//     printf("Character '%c' not found.\n", (char)searchChar);
// 	// }

// 	return 0;
// }
