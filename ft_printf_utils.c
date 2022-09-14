/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:11:03 by pcervill          #+#    #+#             */
/*   Updated: 2022/09/14 10:05:58 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	num;

	num = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			num += write(1, "-2", 2);
			n = 147483648;
		}
		else
		{
			num += write(1, "-", 1);
			n *= -1;
		}
	}
	if (n > 9)
		num += ft_putnbr(n / 10);
	num += ft_putchar((n % 10) + '0');
	return (num);
}

int	ft_putnbr_sn(unsigned int n)
{
	unsigned int	num;

	num = 0;
	if (n > 9)
		num += ft_putnbr_sn(n / 10);
	num += ft_putchar((n % 10) + '0');
	return (num);
}

static int	ft_aux_hexa(unsigned long c, char *hexa)
{
	int	i;

	i = 0;
	if (c >= 16)
		i += ft_aux_hexa(c / 16, hexa);
	i += write(1, hexa + (c % 16), 1);
	return (i);
}

int	ft_dirpoint(unsigned long c, char *hexa)
{
	int	i;

	i = 2;
	ft_putchar('0');
	ft_putchar('x');
	i += ft_aux_hexa(c, hexa);
	return (i);
}
