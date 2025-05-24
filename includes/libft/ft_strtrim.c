/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:06:34 by plantsov          #+#    #+#             */
/*   Updated: 2024/12/10 21:06:35 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	checkstart(char const *s1, char const *set)
{
	size_t	index;
	int		i;

	i = 0;
	index = 0;
	while (set[i] != '\0')
	{
		if (s1[index] == set[i])
		{
			index++;
			i = 0;
		}
		else
		{
			i++;
		}
	}
	return (index);
}

static size_t	checktail(const char *s1, char const *set, size_t s1_len)
{
	size_t	index;
	int		i;

	index = s1_len;
	i = 0;
	while (set[i] != '\0')
	{
		if (s1[index - 1] == set[i])
		{
			index--;
			i = 0;
		}
		else
		{
			i++;
		}
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	s1_len;
	size_t	start;
	size_t	tail;
	size_t	len;

	s1_len = ft_strlen(s1);
	start = checkstart(s1, set);
	tail = checktail(s1, set, s1_len);
	len = tail - start;
	result = ft_substr(s1, start, len);
	return (result);
}
