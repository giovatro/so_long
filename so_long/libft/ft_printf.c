/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:30:48 by gtroiano          #+#    #+#             */
/*   Updated: 2023/08/14 17:39:25 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static void	ft_eval_format(va_list ap, char s, int *len)
{
	if (s == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (s == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (s == 'p')
		ft_putptr(va_arg(ap, void *), len);
	else if (s == 'i' || s == 'd')
		ft_putnbr(va_arg(ap, int), len);
	else if (s == 'u')
		ft_putuint(va_arg(ap, unsigned int), len);
	else if (s == 'x' || s == 'X')
		ft_puthex(va_arg(ap, unsigned int), len, s);
	else if (s == '%')
		ft_putchar(s, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	if (!format)
		return (0);
	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_eval_format(ap, format[++i], &len);
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(ap);
	return (len);
}
