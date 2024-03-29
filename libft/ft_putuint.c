/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:06:19 by gtroiano          #+#    #+#             */
/*   Updated: 2023/08/14 12:21:26 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_putuint(unsigned int u, int *len)
{
	if (u > 9)
		ft_putuint(u / 10, len);
	ft_putchar((u % 10) + 48, len);
}
