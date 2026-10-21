/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:00:42 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/06 17:42:34 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
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
	char	str[6] = "42pis";
	int	result;

	result = ft_str_is_alpha(str);
	printf("%d\n", result);
	return (0);
}
*/
