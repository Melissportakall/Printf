/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:13:32 by melisportak       #+#    #+#             */
/*   Updated: 2023/11/11 21:13:59 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long num)
{
	int		len;
	int		ad_len;

	len = 0;
	if (num < 0)
	{
		num *= -1;
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
	}
	if (num < 10)
	{
		if (ft_putchar(num + '0') == -1)
			return (-1);
	}
	else
	{
		ad_len = ft_putnbr(num / 10);
		if (ad_len < 0)
			return (-1);
		len += ad_len;
		ft_putnbr(num % 10);
	}
	return (len + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
	{
		if (ft_string("(null)") == -1)
			return (-1);
		return (6);
	}
	while (str[++i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
	}
	return (i);
}

int	ft_hex_base(unsigned long int number, char *base, int mod)
{
	int	len;
	int	value;

	len = 0;
	if (mod == -1)
	{
		if (ft_string("0x") == -1)
			return (-1);
		mod = 2;
		len += 2;
	}
	if (number >= 16)
	{
		value = ft_hex_base(number / 16, base, mod);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar(base[number % 16]) == -1)
		return (-1);
	return (len + 1);
}
