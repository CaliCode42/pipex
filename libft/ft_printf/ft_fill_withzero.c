/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_withzero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:31:39 by tcali             #+#    #+#             */
/*   Updated: 2025/04/07 14:11:48 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"
#include <stdio.h>

void	ft_fill_withzero(char *str, size_t n)
{
	char	*ptr;

	ptr = str;
	while (n--)
		*ptr++ = '0';
	*ptr++ = '\0';
}
