/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:25:32 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/20 20:30:49 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int	main(void)
// {
// 	int c;
// 	c = 'r';
// 	int x;
// 	x = 51;
// 	int z;
// 	z = 128;
// 	printf("character is in range : %d \n",ft_isascii(c));
// 	printf("character is in range : %d\n",ft_isascii(x));
// 	printf("character is in range : %d\n",ft_isascii(z));
// 	return(1);
// }