/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:07:33 by ksilva            #+#    #+#             */
/*   Updated: 2026/09/10 17:38:17 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_check_base(char *base, int len)
{
	int	i;
	int	j;

	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_write_digits(long n, char *base, int len)
{
	char	display[33];
	int		i;

	i = 0;
	while (n >= len)
	{
		display[i] = n % len;
		n = n / len;
		i++;
	}
	display[i] = n;
	while (i >= 0)
	{
		write(1, &base[(int)display[i]], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	n;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (!ft_check_base(base, len))
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	ft_write_digits(n, base, len);
}

/*
int	main(void)
{
	ft_putnbr_base(42, "0123456789ABCDEF");
	write(1, "\n", 1);
	return (0);
}
*/
