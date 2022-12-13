/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 07:48:32 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/10 08:08:30 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		len += 6;
		return (len);
	}
	while (s[len])
	{
		ft_putchar(s[len]);
		len++;
	}
	return (len);
}

char	ft_convert(unsigned long long quotient, unsigned long long remainder,
		int base)
{
	remainder = quotient % 16;
	if (remainder < 10)
		return (48 + remainder);
	else
	{
		if (base == 'X')
			return (55 + remainder);
		if (base == 'x')
			return (87 + remainder);
	}
	quotient /= 16;
	return ('\0');
}

int	ft_hex(unsigned long long num, int base)
{
	int					i;
	int					j;
	unsigned long long	remainder;
	char				hex[100];

	i = 0;
	j = 0;
	remainder = 0;
	if (num == 0)
		return (ft_putchar('0'));
	while (num != 0)
	{
		hex[j++] = ft_convert(num, remainder, base);
		num /= 16;
	}
	hex[j] = '\0';
	i = j;
	while (j)
		ft_putchar(hex[--j]);
	return (i);
}

int	ft_pointer(unsigned long pp)
{
	if (!pp)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_hex(pp, 'x') + 2);
}
