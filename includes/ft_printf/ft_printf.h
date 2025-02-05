/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:18:52 by lefoffan          #+#    #+#             */
/*   Updated: 2024/11/26 09:58:10 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putnbr(long long int nb, int *read);
int	ft_base(unsigned long int nb, char *base, int *read);
int	ft_putaddress(void *ptr, int *read);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_print_format(unsigned char format, va_list ap);
int	ft_printf(const char *format, ...);

#endif
