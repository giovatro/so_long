/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:11:58 by gtroiano          #+#    #+#             */
/*   Updated: 2024/02/15 15:12:44 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_lstlen(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

char	**ft_tabcpy(char **in, char **out)
{
	int		i;

	i = 0;
	out = malloc(sizeof(char *) * (ft_lstlen(in) + 1));
	if (!out)
		return (NULL);
	while (in[i])
	{
		out[i] = ft_strdup(in[i]);
		i++;
	}
	out[i] = NULL;
	return (out);
}
