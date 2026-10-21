/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:19:26 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/08 18:51:22 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		j = 0;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	result = ft_strstr("Ola mundo", "mundo");
	printf("%s\n", result ? result : "NULL");
	return (0);
}
*/
