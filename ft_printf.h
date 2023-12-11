/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:13:50 by melisportak       #+#    #+#             */
/*   Updated: 2023/11/11 21:13:51 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putnbr(long num);
int	ft_putchar(char x);
int	ft_string(char *str);
int	ft_hex_base(unsigned long int number, char *base, int mod);
int	ft_printf(const char *str, ...);

#endif
