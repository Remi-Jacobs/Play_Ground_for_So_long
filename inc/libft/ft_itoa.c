/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:48:16 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/22 18:19:08 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	char	*str;
	int		digit_count;
	long	nbr;

	nbr = (long) n;
	digit_count = ft_digit_count(nbr);
	str = (char *)malloc((digit_count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[digit_count] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		digit_count--;
		str[digit_count] = ('0' + (nbr % 10));
		nbr = nbr / 10;
	}
	return (str);
}

// #include<stdio.h>

// int main()
// {
//     int example = 97909237;
//     char *result = ft_itoa(example);

//     if (result != NULL) {
//         printf("%s\n", result);
// 		printf("%zu\n", ft_digit_count(example));
// 		printf("%zu\n", sizeof(result));
//         free(result);
//     } else {
//         printf("ft_itoa failed to allocate memory\n");
//     }

//     return 0;
// }
