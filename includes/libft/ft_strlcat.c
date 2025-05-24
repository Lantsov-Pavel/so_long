/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:08:25 by plantsov          #+#    #+#             */
/*   Updated: 2024/12/10 21:08:27 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_dest;
	size_t	size_src;

	size_dest = ft_strlen((const char *)dest);
	size_src = ft_strlen(src);
	i = size_dest;
	j = 0;
	if (size <= size_dest)
		return (size + size_src);
	i = size_dest;
	while (i < size - 1 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (size_dest + size_src);
}
