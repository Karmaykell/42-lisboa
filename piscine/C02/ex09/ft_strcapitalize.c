/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:45:22 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/07 19:29:29 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	firstletter;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
			firstletter = 1;
		else
			firstletter = !((str[i - 1] >= '0' && str[i - 1] <= '9')
					|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
					|| (str[i - 1] >= 'a' && str[i - 1] <= 'z'));
		if (firstletter)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[64] = "ola, tudo bem? 42palavras quarenta-e-duas; e+um";
	char	*result;

	result = ft_strcapitalize(str);
	printf("%s\n", result);
	return (0);
}
*/
