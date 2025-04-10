/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:49:07 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 20:49:07 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <stdarg.h>

/**
 * Format a string with a size limit
 * 
 * str = The destination buffer
 * size = The maximum number of characters to write to str
 * format = The format string
 * ... = The variable arguments
 * return : (int) nb of chars written if size was large enough.
 */
int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	t_sprintf	s;
	int			len;

	s.format = format;
	va_start(s.ap, format);
	if (!ft_process_format(&s))
	{
		va_end(s.ap);
		return (-1);
	}
	len = ft_strlen(s.result);
	if (size > 0)
	{
		if (len >= (int)size)
			ft_strlcpy(str, s.result, size);
		else
			ft_strlcpy(str, s.result, len + 1);
	}
	free(s.result);
	va_end(s.ap);
	return (len);
}
