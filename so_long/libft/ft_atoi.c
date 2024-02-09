/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:32:39 by gtroiano          #+#    #+#             */
/*   Updated: 2023/07/24 19:19:31 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43)
		str++;
	else if (*str == 45)
	{
		sign = -sign;
		str++;
	}
	while (ft_isdigit(*str))
	{
		value *= 10;
		value += *str - 48;
		str++;
	}
	return (value * sign);
}
