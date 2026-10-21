/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:55:24 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/06 19:01:35 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] >= 'a' && str[i] <= 'z')
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
	char	str[6] = "AbcDE";
	int	result;

	result = ft_str_is_lowercase(str);
	printf("%d\n", result);
	return (0);
}
*/