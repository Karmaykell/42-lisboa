/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:22:43 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/21 14:39:50 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	number;

	number = '5';
	while (number <= '9')
	{
		write (1, &number, 1);
		number++;
	}
}

/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/