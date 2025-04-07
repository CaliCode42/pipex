/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:50:41 by tcali             #+#    #+#             */
/*   Updated: 2025/04/07 14:29:50 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int fd;

	if (ac < 2)
		return (1);
	fd = open(av[1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		return (1);
	ft_printf_fd(fd, "Hello\n");
	close (fd);
	return (0);
}