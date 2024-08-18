/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:46:19 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/21 12:34:54 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new_str = (char *) malloc((s1len + s2len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, s1len + 1);
	ft_strlcat(new_str + s1len, s2, s2len + 1);
	return (new_str);
}

// #include <stdio.h>

// int main()
// {
// 	char *str1 = "Oluremilekun";
// 	char *str2 = "Jacobspppppppppppppppppppp";
// 	char *newstr = ft_strjoin(str1, str2);
// 	printf("%s\n", newstr);
// 	free(newstr);

// 	return 0;
// }
