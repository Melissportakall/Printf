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

int	ft_number_count(long num,int base)
{
	int	len;

	len = 0;
	if(num == 0)
		return (1);
	while(num != 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

int ft_number_count_hex(unsigned long int number)
{
	int	len;

	len = 0;
	while(number != 0)
	{
		number = number / 16;
		len++;
	}
	return(len);
}
int	ft_putnbr(long num)
{
	int		len;

	len = 0;
	if(num < 0)
	{
		len += ft_putchar('-');
		num *= -1;
	}
	if(num == 0)
	{
		return(write(1,"0",1));
	}
	if(num > 9)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar(num % 10 + 48);
	len += ft_number_count(num , 10);
	return(len);
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

int	ft_hex(unsigned long int number, char *base, int mod)
{
	int	len;

	len = 0;
	if (mod == -1)
	{
		if (ft_string("0x") == -1)
			return (-1);
		mod += 2;
	}
	if (number >= 16)
	{
		if (ft_hex(number / 16, base, mod) == -1)
			return (-1);
		len = ft_number_count_hex(number);
	}
	if (ft_putchar(base[number % 16]) == -1)
		return (-1);
	return (len + 1);
}