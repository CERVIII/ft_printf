/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:39:13 by pcervill          #+#    #+#             */
/*   Updated: 2022/05/03 14:36:57 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_putstr(const char *str);
int	ft_putchar(char c);
int	ft_putnbr(int c);
int	ft_putnbr_sn(unsigned int n);
int	ft_hexa(unsigned int c, char *hexa);
int	ft_dirpoint(unsigned long c, char *hexa);

#endif
