/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:54:38 by vebastos          #+#    #+#             */
/*   Updated: 2025/11/04 12:55:47 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putunsignednbr(unsigned int nbr)
{
	size_t	count;

	count = 0;
	if (nbr / 10 > 0)
		count += ft_putunsignednbr(nbr / 10);
	count += ft_putchr((nbr % 10) + '0');
	return (count);
}

size_t	ft_puthex(unsigned long nbr, char format)
{
	size_t	count;

	count = 0;
	if (nbr / 16 > 0)
		count += ft_puthex(nbr / 16, format);
	if (nbr % 16 < 10)
		count += ft_putchr((nbr % 16) + '0');
	else
	{
		if (format == 'x')
			count += ft_putchr((nbr % 16) - 10 + 'a' );
		else
			count += ft_putchr((nbr % 16) - 10 + 'A');
	}
	return (count);
}

size_t	ft_putpointer(void *p)
{
	size_t	count;

	if (!p)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_puthex((unsigned long)p, 'x');
	return (count);
}
