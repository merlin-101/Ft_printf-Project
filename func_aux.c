/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 06:49:13 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/10 08:06:43 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s)
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

unsigned long	ft_plus_ultra(unsigned long n, unsigned long len)
{
	if (n >= 10)
	{
		len = ft_plus_ultra(n / 10, len);
		ft_putchar((n % 10) + '0');
		len++;
	}
	else
	{
		ft_putchar((n % 10) + '0');
		len++;
	}
	return (len);
}

unsigned long	ft_put_nbr(long long n, unsigned long len)
{
	if (n == LONG_MIN)
	{
		write (1, "-9223372036854775808", 20);
		return (len = 20);
	}
	if (n < 0)
	{
		ft_putchar('-');
		len++;
		n = -n;
	}
	if (n > 9)
	{
		len = ft_put_nbr(n / 10, len);
		len = ft_put_nbr(n % 10, len);
	}
	if (n < 10 && n >= 0)
	{
		ft_putchar(n + '0');
		len++;
	}
	return (len);
}
