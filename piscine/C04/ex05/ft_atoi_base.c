/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 18:43:21 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/10 21:05:32 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_skip_prefix(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = *sign * -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	display;
	int	size;
	int	j;

	size = 0;
	while (base[size] != '\0')
		size++;
	sign = 1;
	i = ft_skip_prefix(str, &sign);
	display = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0' && base[j] != str[i])
			j++;
		if (base[j] == '\0')
			return (display * sign);
		display = display * size + j;
		i++;
	}
	return (display * sign);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
	return (0);
}
*/
