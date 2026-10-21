/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 19:46:00 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/05 20:04:52 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	n1;
	int	n2;

	n1 = *a;
	n2 = *b;
	*a = n1 / n2;
	*b = n1 % n2;
}

/*
#include <stdio.h>
int	main(void)
{
	int a = 17;
	int b = 5;

	ft_ultimate_div_mod(&a, &b);
	printf("div = %d, mod = %d\n", a, b);
	return (0);
}
*/