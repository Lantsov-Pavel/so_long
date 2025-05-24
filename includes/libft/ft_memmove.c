/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:04:18 by plantsov          #+#    #+#             */
/*   Updated: 2024/12/10 21:04:20 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_moveforw(unsigned char *d, const unsigned char	*s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void	ft_moveback(unsigned char	*d, const unsigned char	*s, size_t n)
{
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s || d >= (s + n))
		ft_moveforw(d, s, n);
	else
		ft_moveback(d, s, n);
	return (dest);
}
