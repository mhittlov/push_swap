/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhittlov <mhittlov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 06:47:42 by mhittlov          #+#    #+#             */
/*   Updated: 2024/02/03 19:09:53 by mhittlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	a;

	count = 0;
	a = 0;
	while (*(s + a))
	{
		if (*(s + a) != c)
		{
			count++;
			while (*(s + a) && *(s + a) != c)
				a++;
		}
		else if (*(s + a) == c)
			a++;
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	a;

	a = 0;
	while (*(s + a) && *(s + a) != c)
		a++;
	return (a);
}

static void	free_array(size_t a, char **array)
{
	while (a > 0)
	{
		a--;
		free(*(array + a));
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t word_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, get_word_len(&*(s + j), c));
		if (!*(array + i))
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}
