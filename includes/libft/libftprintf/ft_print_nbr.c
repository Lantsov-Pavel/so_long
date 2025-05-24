/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:16:09 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/29 21:17:13 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	upd_ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			count++;
		}
		if (n >= 10)
			count += upd_ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
		count++;
	}
	return (count);
}

static int	ft_putunsnbr_fd(unsigned int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += upd_ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

int	ft_print_nbr(char c, va_list args, int fd)
{
	unsigned int	unum;
	int				num;
	int				result;

	result = 1;
	if (c == 'd' || c == 'i')
	{
		num = va_arg(args, int);
		result = upd_ft_putnbr_fd(num, fd);
	}
	else if (c == 'u')
	{
		unum = va_arg(args, unsigned int);
		result = ft_putunsnbr_fd(unum, fd);
	}
	return (result);
}
