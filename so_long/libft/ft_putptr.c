/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:19:34 by gtroiano          #+#    #+#             */
/*   Updated: 2023/08/14 17:23:20 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(void *p, int *len)
{
	unsigned long	ptr_address;

	ptr_address = (unsigned long)p;
	ft_putstr("0x", len);
	ft_puthex(ptr_address, len, 'x');
}
