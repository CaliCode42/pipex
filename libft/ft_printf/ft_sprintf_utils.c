/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:49:16 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 20:49:16 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <stdarg.h>

char	*ft_handle_char(t_sprintf *s)
{
	char	*result;

	result = (char *)malloc(2);
	if (!result)
		return (NULL);
	result[0] = (char)va_arg(s->ap, int);
	result[1] = '\0';
	return (result);
}

char	*ft_handle_string(t_sprintf *s)
{
	char	*arg;

	arg = va_arg(s->ap, char *);
	if (!arg)
		return (ft_strdup("(null)"));
	return (ft_strdup(arg));
}

char	*ft_handle_int(t_sprintf *s)
{
	return (ft_itoa(va_arg(s->ap, int)));
}

char	*ft_handle_unsigned(t_sprintf *s)
{
	return (ft_itoa(va_arg(s->ap, unsigned int)));
}
