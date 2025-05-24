/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:14:54 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/29 21:15:56 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_chr(char c, va_list args, int fd)
{
	if (c == 'c')
	{
		c = (char)va_arg(args, int);
		ft_putchar_fd(c, fd);
	}
	else if (c == '%')
	{
		ft_putchar_fd('%', fd);
	}
	return (1);
}
