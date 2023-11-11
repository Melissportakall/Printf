/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:13:44 by melisportak       #+#    #+#             */
/*   Updated: 2023/11/11 21:13:45 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdarg.h>

static	int	ft_format(va_list *arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg((*arg), int)));
	else if (format == 's')
		return (ft_string(va_arg((*arg), char *)));
	else if (format == 'p')
		return (ft_hex(va_arg((*arg), unsigned long int),
				"0123456789abcdef", -1));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg((*arg), int)));
	else if (format == 'u')
		return (ft_putnbr(va_arg((*arg), unsigned int)));
	else if (format == 'X')
		return (ft_hex(va_arg((*arg), unsigned int),
				"0123456789ABCDEF", 0));
	else if (format == 'x')
		return (ft_hex(va_arg((*arg), unsigned int),
				"0123456789abcdef", 0));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

static	int	ft_print(va_list *arg, const char *str)
{
	int	i;
	int	len;
	int	de_len;

	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			de_len = ft_format(arg, str[++i]);
			if (de_len == -1)
				return (-1);
			len += de_len - 1;
		}
		else if (ft_putchar(str[i]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	arg;

	va_start(arg, str);
	len = ft_print(&arg, str);
	va_end(arg);
	return (len);
}

#include <stdio.h>
int main()
{
    char a[] = "0x1A3";
    printf("%p\n",&a);
    ft_printf("%p",&a);
}