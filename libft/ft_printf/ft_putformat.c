/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:39:56 by tcali             #+#    #+#             */
/*   Updated: 2025/04/07 14:13:54 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"
#include <unistd.h> 

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putformat(t_printf *list, char c)
{
	ft_putchar(list->fd, c);
	list->nb_chars++;
}
