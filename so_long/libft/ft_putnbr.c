/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:22:04 by gtroiano          #+#    #+#             */
/*   Updated: 2023/08/13 19:28:03 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	else if (n < 0)
	{
		ft_putchar(45, len);
		ft_putnbr(-n, len);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, len);
		ft_putchar((n % 10) + 48, len);
	}
}
