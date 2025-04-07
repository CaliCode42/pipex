/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:07:32 by tcali             #+#    #+#             */
/*   Updated: 2025/04/07 14:11:32 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"

void	ft_check_width(t_printf *list)
{
	if (list->format.is_negative)
		list->format.width -= 1;
	if ((list->format.plus
			|| list->format.space) && (!list->format.is_negative))
		list->format.width -= 1;
	if (list->format.hash
		&& (list->format.uppercase || list->format.lowercase))
		list->format.width -= 2;
}
