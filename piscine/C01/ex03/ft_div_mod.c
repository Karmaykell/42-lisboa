/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 19:03:14 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/15 20:47:30 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}


#include <stdio.h>
int main(void){
	int div;
	int mod;
	int a;
	int b;

	a = 17;
	b = 2;

	ft_div_mod(a, b, &div, &mod);
	printf("%d %d", div, mod);
	return (0);
	
}
*/