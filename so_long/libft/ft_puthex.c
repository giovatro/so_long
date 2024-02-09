/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:44:22 by gtroiano          #+#    #+#             */
/*   Updated: 2023/08/14 13:40:01 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long x, int *len, char s)
{
	char	*alphanum;

	if (s == 'X')
		alphanum = "0123456789ABCDEF";
	else
		alphanum = "0123456789abcdef";
	if (x >= 16)
		ft_puthex((x / 16), len, s);
	ft_putchar(alphanum[x % 16], len);
}
