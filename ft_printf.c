/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:49:52 by pcervill          #+#    #+#             */
/*   Updated: 2022/05/04 17:40:21 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 
#include <stdio.h>
#include <limits.h>

int	ft_hexa(unsigned int c, char *hexa)
{
	int	i;

	i = 0;
	if (c >= 16)
		i += ft_hexa(c / 16, hexa);
	i += write(1, hexa + (c % 16), 1);
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_type(va_list arg, const char str)
{
	int	result;

	result = 0;
	if (str == 'c')
		result += ft_putchar(va_arg(arg, int));
	if (str == 's')
		result += ft_putstr(va_arg(arg, const char *));
	if (str == 'p')
		result += ft_dirpoint(va_arg(arg, unsigned long), "0123456789abcdef");
	if (str == 'd')
		result += ft_putnbr(va_arg(arg, int));
	if (str == 'i')
		result += ft_putnbr(va_arg(arg, int));
	if (str == 'u')
		result += ft_putnbr_sn(va_arg(arg, unsigned int));
	if (str == 'x')
		result += ft_hexa(va_arg(arg, unsigned int), "0123456789abcdef");
	if (str == 'X')
		result += ft_hexa(va_arg(arg, unsigned int), "0123456789ABCDEF");
	if (str == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		result;
	va_list	arg;

	i = 0;
	result = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			result += ft_type(arg, str[i + 1]);
			i++;
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (result);
}

/*int main(void)
{
	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
}*/
