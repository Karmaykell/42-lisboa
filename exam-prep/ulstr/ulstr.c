/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:27:49 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/18 13:08:45 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	
	if(argc == 2)
	{
		i = 0;
	while(argv[1][i] != '\0')
	{
		if(argv[1][i] >= 'a' && argv[1][i] <= 'z'){
		argv[1][i] = argv[1][i] - 32;
		write(1, &argv[1][i], 1);
	}else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z'){
		argv[1][i] = argv[1][i] + 32;
		write(1, &argv[1][i], 1);
	} else {
		write(1, &argv[1][i], 1);
	}

		
		i++;
	}
	write(1, "\n", 1);
	
	} else{
		write(1, "\n", 1);
	}
	
return(0);
}
