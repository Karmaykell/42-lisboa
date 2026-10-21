/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:38:02 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/09 19:54:05 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	count_n;
	int	display;

	i = 0;
	count_n = 0;
	display = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count_n++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		display = display * 10 + (str[i] - '0');
		i++;
	}
	if (count_n % 2 == 1)
		display = display * -1;
	return (display);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
	return (0);
}
*/
