/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:25:42 by vebastos          #+#    #+#             */
/*   Updated: 2025/11/04 12:56:05 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

size_t	ft_putchr(char c);
size_t	ft_putstr(char *s);
size_t	ft_putnbr(long nbr);
size_t	ft_putpointer(void *p);
size_t	ft_putunsignednbr(unsigned int nbr);
size_t	check_type(char type, va_list args);
size_t	ft_puthex(unsigned long nbr, char format);
int		ft_printf(const char *format, ...);

#endif