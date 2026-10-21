/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 13:17:53 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/04 20:15:12 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;
	int	force;

	i = 0;
	force = 1;
	while (force == 1)
	{
		force = 0;
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
				force = 1;
			}
			j++;
		}
		i++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int	tab[5];
	int	i;

	tab[0] = 5;
	tab[1] = 8;
	tab[2] = 9;
	tab[3] = 0;
	tab[4] = 2;
	ft_sort_int_tab(tab, 5);
	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/