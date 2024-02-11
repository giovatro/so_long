/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:14:34 by gtroiano          #+#    #+#             */
/*   Updated: 2024/02/08 18:14:42 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strjoin(char *s1, const char *s2)

{
	char	*c;
	int		i;
	int		i2;

	if (!s2)
		return (NULL);
	i = 0;
	i2 = 0;
	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (c == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
		c[i++] = s2[i2++];
	c[i] = '\0';
	free(s1);
	s1 = NULL;
	return (c);
}
