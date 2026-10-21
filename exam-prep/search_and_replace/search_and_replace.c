/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:01:40 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/18 13:26:09 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;

	if(argc != 4)
	{
		write(1, "\n", 1);
		return(0);
	}

	while(argv[2][i] != '\0'){
		i++;
	}
	
	if(i != 1){
		write(1, "\n", 1);
		return(0);
	}

	j = 0;
	while(argv[3][j] != '\0'){
		j++;
	}
	
	if(i != 1){
		write(1, "\n", 1);
	}
	

	if(j == 1 && i == 1)
	{
		i = 0;
	while(argv[1][i] != '\0')
	{
		if(argv[1][i] == argv[2][0])
		argv[1][i] = argv[3][0];

		write(1, &argv[1][i], 1);

		
		i++;
	}
	}





	write(1, "\n", 1);
	return(0);
}