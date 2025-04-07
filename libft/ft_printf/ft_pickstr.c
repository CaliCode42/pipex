/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pickstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:17:43 by tcali             #+#    #+#             */
/*   Updated: 2025/04/07 14:15:40 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"
#include <stdio.h>

void	ft_pickstr(t_printf *list)
{
	if (list->format.specifier == 's')
		ft_putstr(list, list->format.str);
	else if (ft_present("pdiuxX", list->format.specifier))
		ft_putstr(list, list->format.itoa);
	return ;
}
