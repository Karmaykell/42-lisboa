/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:35:27 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/18 13:58:54 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


static char aux(int i)
{
	char j;
	
	if(i <= 9){
		j = i + '0';
	}

	if(i > 9){
	aux(i / 10);
	j = i % 10;
	}
	return(j);
}

void	fizzbuzz(void)
{
	int i;
	char j;
	
	i = 1;

	while(i <= 100)
	{
		if(i % 4 == 0){
		write(1, "fizz", 4);
		write(1, "\n", 1);
		}
		else if(i % 7 == 0){
		write(1, "buzz", 4);
		write(1, "\n", 1);
		} 
		if((i % 7 == 0) && (i % 4 == 0))
		{
			write(1, "fizzbuzz", 8);
			write(1, "\n", 1);
		}else{
			j = aux(i);
			write(1, &j, 2);
			write(1, "\n", 1);
		}	
		i++;
	}
}

int main(void)
{
	fizzbuzz();
	return(0);
}