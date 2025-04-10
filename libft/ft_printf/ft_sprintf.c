/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:50:02 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 20:50:02 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <stdarg.h>

char	*ft_handle_format(t_sprintf *s, int *i)
{
	char	*result;

	(*i)++;
	if (s->format[*i] == 'c')
		result = ft_handle_char(s);
	else if (s->format[*i] == 's')
		result = ft_handle_string(s);
	else if (s->format[*i] == 'd' || s->format[*i] == 'i')
		result = ft_handle_int(s);
	else if (s->format[*i] == 'u')
		result = ft_handle_unsigned(s);
	else if (s->format[*i] == 'x')
		result = ft_handle_hex(s, 0);
	else if (s->format[*i] == 'X')
		result = ft_handle_hex(s, 1);
	else if (s->format[*i] == 'p')
		result = ft_handle_pointer(s);
	else if (s->format[*i] == '%')
		result = ft_handle_percent();
	else
		return (NULL);
	return (result);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	t_sprintf	s;

	s.format = format;
	va_start(s.ap, format);
	if (!ft_process_format(&s))
	{
		va_end(s.ap);
		return (-1);
	}
	s.len = ft_strlen(s.result);
	ft_strlcpy(str, s.result, s.len + 1);
	free(s.result);
	va_end(s.ap);
	return (s.len);
}
