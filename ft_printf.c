/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 01:45:17 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/10 08:09:50 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_converters(va_list args, const char s)
{
	int		len;

	len = 0;
	if (s == 'c')
		len += ft_putchar(va_arg(args, int));
	if (s == 'd' || s == 'i')
		len += ft_put_nbr(va_arg(args, int), 0);
	if (s == 'u')
		len += ft_plus_ultra(va_arg(args, unsigned int), 0);
	if (s == 's')
		len += ft_putstr(va_arg(args, char *));
	if (s == 'p')
		len += ft_pointer(va_arg(args, unsigned long));
	if (s == 'x' || s == 'X')
		len += ft_hex(va_arg(args, unsigned int), s);
	if (s == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{	
	va_list				pointer;
	unsigned int		i;
	unsigned int		len;

	va_start(pointer, s);
	i = 0;
	len = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_converters(pointer, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(pointer);
	return (len);
}
