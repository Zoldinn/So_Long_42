/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:26:57 by lefoffan          #+#    #+#             */
/*   Updated: 2024/11/26 11:10:38 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	read;

	read = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
		read += write(1, str++, 1);
	return (read);
}

int	ft_putnbr(long long int nb, int *read)
{
	char	res;

	if (nb < 0)
	{
		*read += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, read);
	res = '0' + (nb % 10);
	return (*read += write(1, &res, 1));
}

int	ft_base(unsigned long int nb, char *base, int *read)
{
	unsigned int	len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if ((nb / len_base) != 0)
		ft_base(nb / len_base, base, read);
	return (*read += write(1, &base[nb % len_base], 1));
}

int	ft_putaddress(void *ptr, int *read)
{
	int	count;

	count = 0;
	if (!ptr)
		return (*read += ft_putstr("(nil)"));
	*read += ft_putstr("0x");
	*read += ft_base((long long int) ptr, "0123456789abcdef", &count);
	return (*read);
}
