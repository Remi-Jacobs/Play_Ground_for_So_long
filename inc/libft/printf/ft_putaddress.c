/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:51:12 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/06 12:47:08 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	hex_digit(int h)
{
	if (h >= 0 && h < 10)
		return (h + '0');
	else
		return (h + 'a' - 10);
}

int	ft_putaddress(char *c)
{
	unsigned long long	p;
	int					nibble;
	int					num_bits;
	int					add_len;

	p = (unsigned long long)c;
	add_len = 0;
	add_len += ft_print_str("0x");
	num_bits = sizeof(p) * 8;
	if (p == 0)
	{
		add_len += ft_print_char('0');
		return (add_len);
	}
	while (num_bits > 0 && ((p >> (num_bits - 4)) & 0xf) == 0)
	{
		num_bits -= 4;
	}
	while (num_bits > 0)
	{
		nibble = (p >> (num_bits - 4)) & 0xf;
		add_len += ft_print_char(hex_digit(nibble));
		num_bits -= 4;
	}
	return (add_len);
}

// #include <stdio.h>
// int main() 
// {
// 	char *message = "Hello, World!";
// 	ft_putaddress(message);
// 	ft_print_char('\n');  // Newline for better output
// 	printf("%p\n", message);
// 	printf("%d\n",printf("%p", message));
// 	printf("%d\n",ft_putaddress(message));
// 	return 0;
// }
