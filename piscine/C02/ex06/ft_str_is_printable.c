/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:13:49 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/06 19:15:35 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] >= ' ' && str[i] <= '~')
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

	result = ft_str_is_printable(str);
	printf("%d\n", result);
	return (0);
}
*/