/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:05:57 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/29 21:11:05 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_puthex_fd(char *hex_form, unsigned int unum, int fd)
{
	int	count;

	count = 0;
	if (unum >= 16)
		count += ft_puthex_fd(hex_form, unum / 16, fd);
	ft_putchar_fd(hex_form[unum % 16], fd);
	count++;
	return (count);
}

int	ft_print_hex(char c, va_list args, int fd)
{
	unsigned int	hnum;
	char			*hex_form;
	int				result;

	hnum = va_arg(args, unsigned int);
	hex_form = "0123456789abcdef";
	if (c == 'X')
		hex_form = "0123456789ABCDEF";
	result = ft_puthex_fd(hex_form, hnum, fd);
	return (result);
}
