/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:24:48 by vebastos          #+#    #+#             */
/*   Updated: 2025/11/04 12:49:09 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_type(char type, va_list args)
{
	size_t	count;

	count = 0;
	if (type == 'c')
		count += ft_putchr(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		count += ft_putpointer(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		count += ft_putunsignednbr(va_arg(args, int));
	else if (type == 'x')
		count += ft_puthex(va_arg(args, unsigned int), type);
	else if (type == 'X')
		count += ft_puthex(va_arg(args, unsigned int), type);
	else if (type == '%')
		count += ft_putchr('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	printed;
	va_list	args;

	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed += check_type(format[i + 1], args);
			i++;
		}
		else
			printed += ft_putchr(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}

// int	main(void)
// {
// 	char        c = 'H';
// 	const char  str[] = "Hello World!";
// 	int         i = -12345;
// 	int         j = 12345; 
// 	unsigned int k = 6789;
// 	int         l = 4095;
// 	void        *ptr = &l;
// 	int	count = 0;
// 	int	count1 = 0;

// 	count = ft_printf("C value: %c\n", c);
// 	count += ft_printf("Str value: %s\n", str);
// 	count += ft_printf("I value: %d\n", i);
// 	count += ft_printf("J value: %i\n", j);
// 	count += ft_printf("K value (unsigned): %u\n", k);
// 	count += ft_printf("L value (hex lowercase): %x\n", l);
// 	count += ft_printf("L value (hex uppercase): %X\n", l);
// 	count += ft_printf("Pointer value: %p\n", ptr);
// 	count += ft_printf("Null pointer test: %p\n", NULL);

// 	count1 = printf("C value: %c\n", c);
// 	count1 += printf("Str value: %s\n", str);
// 	count1 += printf("I value: %d\n", i);
// 	count1 += printf("J value: %i\n", j);
// 	count1 += printf("K value (unsigned): %u\n", k);
// 	count1 += printf("L value (hex lowercase): %x\n", l);
// 	count1 += printf("L value (hex uppercase): %X\n", l);
// 	count1 += printf("Pointer value: %p\n", ptr);
// 	count1 += printf("Null pointer test: %p\n", NULL);

// 	printf("Count: %d, Count1: %d", count, count1);
// 	return (0);
// }