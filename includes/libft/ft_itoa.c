/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:03:10 by plantsov          #+#    #+#             */
/*   Updated: 2024/12/10 21:03:12 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_addnums(char *str, int index, unsigned int num)
{
	while (num != 0)
	{
		str[index] = (num % 10) + '0';
		num = num / 10;
		index--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int		num;
	char				*result;
	int					len;
	int					i;

	if (n < 0)
		num = n * (-1);
	else
		num = n;
	len = ft_intlen(n);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (num == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (n < 0)
		result[0] = '-';
	i = len - 1;
	result = ft_addnums(result, i, num);
	return (result);
}
