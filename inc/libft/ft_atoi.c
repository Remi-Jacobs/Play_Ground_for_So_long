/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:13:08 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/21 19:15:07 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	answer;
	int	neg;

	i = 0;
	answer = 0;
	neg = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		answer = (answer * 10) + (str[i] - 48);
		i++;
	}
	return (answer * neg);
}

// #include <stdio.h>

// int main()
// {
//     const char *sample = " ±235783";
//     int result;

//     result = ft_atoi(sample);
//     printf("%d\n", result);
//     return (0);
// }