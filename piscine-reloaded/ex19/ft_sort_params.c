/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:58:09 by ksilva            #+#    #+#             */
/*   Updated: 2026/10/20 19:45:27 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_putchar(char c);

void	print_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	smallest_word(int argc, char **argv)
{
	int	idx;
	int	i;

	i = 1;
	while (argv[i] == NULL)
		i++;
	idx = i;
	while (i < argc)
	{
		if (argv[i] != NULL)
		{
			if (ft_strcmp(argv[i], argv[idx]) < 0)
				idx = i;
		}
		i++;
	}
	return (idx);
}

int	main(int argc, char **argv)
{
	int	idx;
	int	i;

	i = 1;
	while (i < argc)
	{
		idx = smallest_word(argc, argv);
		print_word(argv[idx]);
		argv[idx] = NULL;
		i++;
	}
	return (0);
}
