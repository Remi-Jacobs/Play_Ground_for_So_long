/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:30:28 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/12 15:37:55 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
//     int c;
//     c = 'r';
//     int x;
//     x = 3452453;
//     printf("character is in range : %d \n",ft_isalpha(c));
//     printf("character is in range : %d\n",ft_isalpha(x));
//     return(1);
// }