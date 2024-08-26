/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:50:10 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/20 20:30:43 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
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
// 	c = '8';
// 	int x;
// 	x = 'a';
// 	printf("character is in range : %d \n",ft_isdigit(c));
// 	printf("character is in range : %d\n",ft_isdigit(x));
// 	return(1);
// }