/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:20:12 by plantsov          #+#    #+#             */
/*   Updated: 2024/12/11 21:42:54 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	wdcount(char const *s, char c)
{
	unsigned int	cnwords;
	unsigned int	flagwd;

	cnwords = 0;
	flagwd = 0;
	while (*s)
	{
		if ((*s != c) && (flagwd == 0))
		{
			flagwd = 1;
			cnwords++;
		}
		else if (*s == c)
			flagwd = 0;
		s++;
	}
	return (cnwords);
}

static void	putwd(char const *s, char c, char **word)
{
	unsigned int	start;
	unsigned int	i;
	unsigned int	flag;

	i = 0;
	flag = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (flag == 0))
		{
			flag = 1;
			start = i;
		}
		else if ((s[i] == c) && (flag == 1))
		{
			flag = 0;
			*word++ = ft_substr(s, start, (size_t)i - (size_t)start);
		}
		i++;
	}
	if (flag == 1)
		*word++ = ft_substr(s, start, (size_t)i - (size_t)start);
	*word = NULL;
}

static void	freemem(char **result, unsigned int words)
{
	unsigned int	i;

	i = 0;
	while (i < words)
	{
		if (result[i] != NULL)
			free(result[i]);
		i++;
	}
}

static int	checkmem(char **result, unsigned int words)
{
	unsigned int	i;

	i = 0;
	while (i < words)
	{
		if (result[i] == NULL)
		{
			freemem(result, words);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	cnwords;

	cnwords = wdcount(s, c);
	result = (char **)malloc((cnwords + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (cnwords == 0)
		*result = NULL;
	else
		putwd(s, c, result);
	if (checkmem(result, cnwords) != 0)
	{
		free(result);
		result = NULL;
	}
	return (result);
}
