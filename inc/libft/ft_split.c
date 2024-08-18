/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:47:42 by ojacobs           #+#    #+#             */
/*   Updated: 2024/07/25 17:39:36 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	in_substr;

	in_substr = 0;
	count = 0;
	while (*s != '\0')
	{
		if (in_substr == 1 && *s == c)
			in_substr = 0;
		if (in_substr == 0 && *s != c)
		{
			in_substr = 1;
			count++;
		}
		s++;
	}
	return (count);
}

//i = index of last successfully allocated str
static void	ft_freeall(char **result, size_t i)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
}

//len = s - start from process_word
static int	ft_allcopy(char **result, const char *start, size_t len)
{
	*result = (char *)malloc(sizeof(char) * (len + 1));
	if (*result == NULL)
		return (0);
	ft_strlcpy(*result, start, len + 1);
	return (1);
}

//using ptr to modify const = undefined behavior. Use w care
static const char	*process_word(char const *s, char c,
	char **result, size_t i)
{
	const char	*start;

	start = s;
	while (*s != c && *s != '\0')
		s++;
	if (!ft_allcopy(&result[i], start, s - start))
	{
		ft_freeall(result, i);
		return (NULL);
	}
	return (s);
}

//2d array, i=word count index for result array
//result = allocates memory for the array of pointers
char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	result = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			s = process_word(s, c, result, i);
			if (s == NULL)
				return (NULL);
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

/*
#include <stdio.h>

int main ()
{
	char	*problem = "Her and Anu are Mums so ";
	char	c = ' ';
	int i = 0;
	char	**split = ft_split (problem, c);
	while (split[i] != NULL)
	{
		printf("%s\n", split[i]);
		i++;
	}

	free(split);
	return 0;
}
// #include <stdio.h>

int main()
{
    char **result = ft_split(input_string, ' ');

    if (result)
    {
        int i = 0;
        while (result[i] != NULL)
        {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]); // Remember to free each string
            i++;
        }

        free(result); // Finally, free the array of strings
    }
    else
    {
        printf("ft_split returned NULL\n");
    }

    return 0;
}*/
