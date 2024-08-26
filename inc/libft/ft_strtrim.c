/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:47:04 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/21 12:39:16 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	nl;
	size_t	i;

	new_str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		nl = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (nl > i && ft_strchr(set, s1[nl - 1]))
			nl--;
		new_str = (char *)malloc ((nl - i + 1) * sizeof(char));
		if (new_str == NULL)
			return (NULL);
		else
			ft_strlcpy(new_str, &s1[i], nl - i + 1);
	}
	return (new_str);
}

// #include <stdio.h>
// int main()
// {
// 	char const *all_apples = "Apple for jobs here elppapp";
// 	char const *bad_apples = "apply";

// 	char *apples = ft_strtrim(all_apples, bad_apples);

// 	printf("%s\n", apples);

// 	free(apples);

// 	return 0;
// }
