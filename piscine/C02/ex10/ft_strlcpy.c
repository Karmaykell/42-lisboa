/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:29:43 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/07 18:43:40 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (size > 0 && i < size - 1)
			dest[i] = src[i];
		i++;
	}
	if (size > 0 && i < size)
		dest[i] = '\0';
	else if (size > 0)
		dest[size - 1] = '\0';
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	char			dest[10];
	unsigned int	result;

	result = ft_strlcpy(dest, "Hello World", 5);
	printf("dest: %s | retorno: %u\n", dest, result);
	return (0);
}
*/
