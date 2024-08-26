/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:20:03 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/06 12:57:39 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

int	ft_print_hex(unsigned int h, const char format)
{
	char	hex[sizeof(unsigned int) * 2 + 1];
	int		i;

	i = 0;
	if (h == 0)
	{
		return (ft_print_char('0'));
	}
	while (h > 0)
	{
		if (h % 16 < 10)
			hex[i] = (h % 16) + '0';
		else if (h % 16 > 9 && format == 'x')
			hex[i] = (h % 16) + 'a' - 10;
		else if (h % 16 > 9 && format == 'X')
			hex[i] = (h % 16) + 'A' - 10;
		h /= 16;
		i++;
	}
	hex[i] = '\0';
	while (i > 0)
	{
		ft_putchar(hex[--i]);
	}
	return (ft_strlen(hex));
}

// #include <stdio.h>

// int main()
// {
// 	unsigned int sam = 5908;
// 	const char form = 'X';
// 	ft_print_hex(sam, form);
// 	printf("%X\n", sam);
// 	printf("%d\n",printf("%X", sam - 5000));
// 	printf("%d\n",ft_print_hex(sam - 5000, form));
// 	return 0;
// }