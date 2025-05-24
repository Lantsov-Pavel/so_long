/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:13:59 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/29 21:15:40 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_putptr_fd(char *hex_form, size_t st, int fd)
{
	int	count;

	count = 0;
	if (st >= 16)
		count += ft_putptr_fd(hex_form, st / 16, fd);
	ft_putchar_fd(hex_form[st % 16], fd);
	count++;
	return (count);
}

int	ft_print_ptr(va_list args, int fd)
{
	size_t	ptr;
	int		result;

	ptr = (size_t)va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	result = 2 + ft_putptr_fd("0123456789abcdef", ptr, fd);
	return (result);
}
