/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:04:22 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/29 21:05:08 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_print_str(va_list args, int fd)
{
	char	*s;
	int		result;

	result = 0;
	s = va_arg(args, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	result = ft_strlen(s);
	ft_putstr_fd(s, fd);
	return (result);
}
