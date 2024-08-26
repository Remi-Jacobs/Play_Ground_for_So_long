/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:50:33 by ojacobs           #+#    #+#             */
/*   Updated: 2023/12/23 05:59:54 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*totalarray;

	total_size = count * size;
	totalarray = malloc(total_size);
	if (totalarray == NULL)
	{
		return (NULL);
	}
	ft_bzero(totalarray, total_size);
	return (totalarray);
}

// #include <stdio.h>
// int main()
// {
//  int person = 10;
//     size_t organs = sizeof(int);

//     // Allocate memory for an array of integers
//     int *myint = (int *)ft_calloc(person, organs);
//     if (myint == NULL) {
//         fprintf(stderr, "Memory allocation failed\n");
//         return 1;
//     }

//     // Print the values in the allocated memory using a while loop
//     printf("Values in myInt after allocation:\n");
//     int i = 0;
//     while (i < person) {
//         printf("%d ", myint[i]);
//         i++;
//     }
//     printf("\n");

//     // Free the allocation
//     free(myint);

//     return 0;
// }