/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:56:48 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/20 20:33:45 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main(void)
// {
// 	int c;
// 	c = 'r';
// 	int x;
// 	x = 31;
// 	int z;
// 	z = 128;
// 	if(ft_isprint(c))
// 	{
// 		printf("character is in range : %d \n", c);
// 	}
// 	else
// 	{
// 		printf("character is not in range : %d\n", c);
// 	}
// 	if(ft_isprint(x))
// 	{
// 		printf("character is in range : %d \n", x);
// 	}
// 	else
// 	{
// 		printf("character is not in range : %d\n", x);
// 	}
// 	if(ft_isprint(z))
// 	{
// 		printf("character is in range : %d \n", z);
// 	}
// 	else
// 	{
// 		printf("character is not in range : %d\n", z);
// 	}
// 	return(0);
// }