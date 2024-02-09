/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:14:14 by gtroiano          #+#    #+#             */
/*   Updated: 2023/07/31 11:40:33 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_calloc(size_t count, size_t n)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = (char *)malloc(count * n);
	if (!ptr)
		return (NULL);
	while (i < count * n)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
