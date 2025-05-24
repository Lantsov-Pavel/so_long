/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:06:44 by plantsov          #+#    #+#             */
/*   Updated: 2024/12/11 20:25:55 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		result = (char *)ft_calloc(1, sizeof(char));
		if (!result)
			return (NULL);
		return (result);
	}
	if (len > s_len - (size_t)start)
		len = s_len - start;
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, len);
	return (result);
}
