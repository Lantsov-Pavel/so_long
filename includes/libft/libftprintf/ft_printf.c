/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:47:07 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/29 21:18:48 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_choose_type(char c, va_list args, int *len)
{
	int	fd;

	fd = 1;
	if (c == 'd' || c == 'i' || c == 'u')
		*len += ft_print_nbr(c, args, fd);
	else if (c == 'c' || c == '%')
		*len += ft_print_chr(c, args, fd);
	else if (c == 'x' || c == 'X')
		*len += ft_print_hex(c, args, fd);
	else if (c == 's')
		*len += ft_print_str(args, fd);
	else if (c == 'p')
		*len += ft_print_ptr(args, fd);
	return (*len);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			len = ft_choose_type(*input, args, &len);
		}
		else
		{
			ft_putchar_fd(*input, 1);
			len++;
		}
		input++;
	}
	va_end(args);
	return (len);
}
