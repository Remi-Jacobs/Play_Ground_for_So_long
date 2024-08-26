/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:14:50 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/06 13:01:55 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_digit_count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

// static char	*ft_itoa(int n)
// {
// 	char	*str;
// 	int		digit_count;
// 	long	nbr;

// 	nbr = (long) n;
// 	digit_count = ft_digit_count(nbr);
// 	str = (char *)malloc((digit_count + 1) * sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	str[digit_count] = '\0';
// 	if (n == 0)
// 		str[0] = '0';
// 	if (n < 0)
// 	{
// 		str[0] = '-';
// 		nbr = -nbr;
// 	}
// 	while (nbr != 0)
// 	{
// 		digit_count--;
// 		str[digit_count] = ('0' + (nbr % 10));
// 		nbr = nbr / 10;
// 	}
// 	return (str);
// }

int	ft_print_num(int c)
{
	int		count;
	char	*num;

	count = 0;
	count = ft_digit_count (c);
	num = (ft_itoa(c));
	ft_putstr(num);
	free (num);
	return (count);
}

// #include <stdio.h>

// int main()
// {
// 	int number = '\0';
// 	ft_print_num(number);
// 	ft_putchar('\n');
// 	printf("%d", printf("%d",number));
// 	return (0);
// }
