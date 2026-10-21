/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 19:17:37 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/17 18:46:15 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	k = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	if (i >= size)
	{
		while (src[k] != '\0')
			k++;
		return (size + k);
	}
	j = i;
	while ((i < size - 1) && (src[i - j] != '\0'))
	{
		dest[i] = src[i - j];
		i++;
	}
	dest[i] = '\0';
	while (src[i - j] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>
int main(void)
{
	char dest[20] = "Hello ";
	unsigned int result = ft_strlcat(dest, "World", 20);
	printf("dest: %s | retorno: %u\n", dest, result);
	return (0);
}
*/
