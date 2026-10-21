/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:32:18 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/21 14:05:52 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int result;
	int count_n;

	i = 0;
	count_n = 0;
	result = 0;

	while(((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
	{
		i++;
	}

	while(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
		count_n++;
		
		i++;
	}

	while(str[i] != '\0')
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}else{
			if(count_n % 2 == 0)
			return(result);

			if(count_n % 2 != 0)
			return(result * -1);
		}
		i++;
	}
	
	if(count_n % 2 != 0)
	result = result * -1;

	return(result);
	
}

// #include <stdio.h>
// int main(void)
// {
// 	int result;
// 	char str[] = "   	 	 	 	-+-+-+-+-+-+---98765";
// 	result = ft_atoi(str);
// 	printf("%d", result);
// 	return(0);
// }