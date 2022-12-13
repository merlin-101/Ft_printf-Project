/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 01:45:56 by rnarciso          #+#    #+#             */
/*   Updated: 2022/12/10 08:13:28 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int				ft_printf(const char *s, ...);
size_t			ft_converters(va_list args, const char s);
int				ft_putchar(char c);
unsigned long	ft_put_nbr(long long n, unsigned long len);
unsigned long	ft_plus_ultra(unsigned long n, unsigned long len);
int				ft_putstr(char *s);
size_t			ft_strlen(const char *s);
int				ft_pointer(unsigned long pp);
int				ft_hex(unsigned long long num, int base);
char			ft_convert(unsigned long long quotient,
					unsigned long long remainder, int base);

#endif