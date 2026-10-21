/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:27:01 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/21 15:48:28 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int i;
	int j;
	int *result;

	if(start < end)
	{
		result = malloc((end - start + 1) *sizeof(int));
	}

	if(start > end)
	{
		result = malloc((start - end + 1) *sizeof(int));
	}

	if(start == end)
	{
		result = malloc(1 *sizeof(int));
	}
	
	
	if(result == NULL)
	return NULL;

	if(start > end)
	{
	i = start;
	j = 0;

	while(i >= end)
	{
		result[j] = i;
		i--;
		j++;
	}
	}

	if(start < end)
	{
	i = start;
	j = 0;

	while(i <= end)
	{
		result[j] = i;
		i++;
		j++;
	}
	}

	if(start == end)
	{
		result[0] = start;
	}
	

	return(result);
	
}