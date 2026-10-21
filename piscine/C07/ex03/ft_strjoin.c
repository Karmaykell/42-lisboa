/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:20:38 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/16 19:29:21 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_total_len(int size, char **strs, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < size)
	{
		count = count + ft_strlen(strs[i]);
		i++;
	}
	count = count + (size - 1) * ft_strlen(sep);
	count++;
	return (count);
}

static void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*endstr;
	int		i;

	if (size == 0)
	{
		endstr = malloc(1 * sizeof(char));
		if (endstr == NULL)
			return (NULL);
		endstr[0] = '\0';
		return (endstr);
	}
	endstr = malloc(ft_total_len(size, strs, sep) * sizeof(char));
	if (endstr == NULL)
		return (NULL);
	endstr[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(endstr, strs[i]);
		if (i < size - 1)
			ft_strcat(endstr, sep);
		i++;
	}
	return (endstr);
}
