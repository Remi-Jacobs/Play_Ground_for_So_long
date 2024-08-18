/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:18:00 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/21 12:35:16 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
