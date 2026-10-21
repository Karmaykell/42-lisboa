/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:22:40 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/06 19:37:34 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[6] = "abcde";
	char	*result;

	result = ft_strupcase(str);
	printf("%s\n", result);
	return (0);
}
*/
