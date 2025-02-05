/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:30:40 by lefoffan          #+#    #+#             */
/*   Updated: 2024/11/26 11:18:58 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(unsigned char format, va_list ap)
{
	int	read;

	read = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int), &read));
	else if (format == 'u')
		return (ft_base(va_arg(ap, unsigned int), "0123456789", &read));
	else if (format == 'x')
		return (ft_base(va_arg(ap, unsigned int), "0123456789abcdef", &read));
	else if (format == 'X')
		return (ft_base(va_arg(ap, unsigned int), "0123456789ABCDEF", &read));
	else if (format == 'p')
		return (ft_putaddress(va_arg(ap, void *), &read));
	else
		return (ft_putchar('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		read;

	read = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			read += ft_print_format(*(++format), ap);
		else
			read += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (read);
}
/* 
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	unsigned int	read;
	unsigned int	read2;

	printf("\n--- ft_printf VS printf ---\n");
	read = ft_printf("%d\n", INT_MAX);
	read2 = printf("%d\n",INT_MAX);
	
	printf("\n--- read ---\n");
	printf("ft_printf : %d\n", read);
	printf("printf : %d\n", read2);
	return (0);
} */