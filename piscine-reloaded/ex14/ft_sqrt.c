/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:19:25 by ksilva            #+#    #+#             */
/*   Updated: 2026/10/20 17:01:35 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	i;
	long int	n;

	n = nb;
	i = 0;
	if (n <= 0)
	{
		return (0);
	}
	while (i * i < n)
		i++;
	if (i * i == n)
		return (i);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(9));
	return (0);
}
*/
