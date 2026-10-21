/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:41:15 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/08 15:13:28 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = i;
	while (src[i - j] != '\0' && (i - j) < nb)
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

	result = ft_strncat(dest, "World!!!", 5);
	printf("%s\n", result);
	return (0);
}
*/
