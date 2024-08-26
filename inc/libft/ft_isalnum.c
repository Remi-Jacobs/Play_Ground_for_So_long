/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:59:18 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/21 12:37:15 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) || ft_isdigit(c)))
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
// 	x = 51;
// 	int z;
// 	z = '/';
// 	printf("character is in range : %d \n",ft_isalnum(c));
// 	printf("character is in range : %d\n",ft_isalnum(x));
// 	printf("character is in range : %d\n",ft_isalnum(z));
// 	return(1);
// }