/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 20:37:02 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/16 16:16:26 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	int	*tab;
	int	n;

	n = ft_ultimate_range(&tab, 3, 7);
	printf("%d %d %d\n", n, tab[0], tab[n - 1]);
	free(tab);
	return (0);
}
*/
