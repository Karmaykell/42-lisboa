/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilva <ksilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 17:18:29 by ksilva            #+#    #+#             */
/*   Updated: 2026/10/21 18:55:29 by ksilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

static void	read_write(int fd)
{
	char	buffer[1024];
	int		n;

	n = read(fd, buffer, 1024);
	while (n > 0)
	{
		write(1, buffer, n);
		n = read(fd, buffer, 1024);
	}
	if (n == -1)
		write(2, "Cannot read file.\n", 18);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	read_write(fd);
	close(fd);
	return (0);
}
