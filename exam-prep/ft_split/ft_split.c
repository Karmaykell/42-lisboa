/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:48:28 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/23 15:33:52 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int is_sep(char c)
{

	if(c == ' ' || c == '\t' || c == '\n')
	return(1);

	return(0);
}

static int count_wods(char *str)
{
	int i;
	int count_wods;

	count_wods = 0;
	i = 0;

	while(str[i] != '\0')
	{
		if((i == 0 && is_sep(str[i]) != 1) || (is_sep(str[i]) != 1 && is_sep(str[i - 1]) == 1))
		count_wods++;
		i++;
	}

	return(count_wods);
}

static int wods_len(char *str, int i)
{
	int size;

	size = 0;

	while(is_sep(str[i + size]) != 1 && str[i + size] != '\0')
	size++;

	return(size);
}

char	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **strs;
	int len;
	
	strs = malloc((count_wods(str) + 1) * sizeof(char *));

	if(strs == NULL)
	return NULL;

	j = 0;
	i = 0;
	while(str[i] != '\0')
	{
		len = 0;
		if((i == 0 && is_sep(str[i]) != 1) || (is_sep(str[i]) != 1 && is_sep(str[i - 1]) == 1))
		{
			len = wods_len(str, i);
			strs[j] = malloc(len * sizeof(char) + 1);

			if(strs[j] == NULL)
			return NULL;
			
			k = 0;
			while(k < len)
			{
				strs[j][k] = str[i + k];
				k++;
			}
			strs[j][k] = '\0';
			j++;
		}
		i++;
	}

	strs[j] = NULL;
	return(strs);
	
	
}
