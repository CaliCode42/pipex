/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_present.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:22:05 by tcali             #+#    #+#             */
/*   Updated: 2025/04/07 14:12:07 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"

int	ft_present(const char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		++str;
	}
	return (0);
}
