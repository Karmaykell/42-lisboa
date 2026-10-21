/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:45:27 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/06 18:52:54 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[6] = "42195";
	int	result;

	result = ft_str_is_numeric(str);
	printf("%d\n", result);
	return (0);
}
*/
