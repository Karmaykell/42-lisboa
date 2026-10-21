/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:47:01 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/07 20:01:15 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = i;
	while (src[i - j] != '\0')
	{
		dest[i] = src[i - j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	dest[20] = "Hello ";
	char	*result;

	result = ft_strcat(dest, "World");
	printf("%s\n", result);
	return (0);
}
*/
