/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 20:18:58 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/21 18:11:58 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ints;

	if (min >= max)
		return (NULL);
	
	ints = malloc((max - min) * sizeof(int));
	
	if (ints == NULL)
		return (NULL);
	
	i = 0;
	while (i < max - min)
	{
		ints[i] = min + i;
		i++;
	}
	return (ints);
}
