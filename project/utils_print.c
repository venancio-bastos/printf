/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:01:37 by vebastos          #+#    #+#             */
/*   Updated: 2025/11/04 12:55:46 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s)
{
	size_t	count;
	size_t	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	i = 0;
	while (s[i])
	{
		count += ft_putchr(s[i]);
		i++;
	}
	return (count);
}

size_t	ft_putnbr(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchr('-');
		nbr *= -1;
	}
	if (nbr / 10 > 0)
		count += ft_putnbr(nbr / 10);
	count += ft_putchr((nbr % 10) + '0');
	return (count);
}
