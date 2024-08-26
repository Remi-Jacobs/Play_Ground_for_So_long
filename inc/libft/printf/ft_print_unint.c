/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:19:52 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 18:58:12 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_unint_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*ft_unitoa(unsigned int n)
{
	char	*str;
	int		digit_count;

	digit_count = ft_unint_count(n);
	str = (char *)malloc((digit_count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[digit_count] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		digit_count--;
		str[digit_count] = ('0' + (n % 10));
		n = n / 10;
	}
	return (str);
}

int	ft_print_unint(unsigned int n)
{
	int		num_length;
	char	*num;

	num_length = 0;
	num_length = ft_unint_count(n);
	num = (ft_unitoa(n));
	ft_putstr (num);
	free (num);
	return (num_length);
}

// int main() 
// {
// 	unsigned int number = 1000000;
// 	ft_print_unint(number - 100);
// 	ft_putchar('\n');
// 	ft_print_unint(ft_print_unint(number - 100));
// 	ft_putchar('\n');
// 	printf("%d\n", printf("%u",number - 100));
// 	printf("%u\n", number - 100);
// 	return (0);
// }
