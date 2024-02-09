/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:17:22 by gtroiano          #+#    #+#             */
/*   Updated: 2024/02/08 18:17:25 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_data *data)
{
	write (1, "You won!\n", 10);
	ft_printf("Is %d moves really the best you can do?\n", data->counter);
	exit(EXIT_SUCCESS);
}
