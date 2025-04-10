/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:49:54 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 20:49:54 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <stdarg.h>

char	*ft_handle_hex(t_sprintf *s)
{
	char	*arg;
	char	*result;

	arg = ft_itoa(va_arg(s->ap, unsigned int));
	if (!arg)
		return (NULL);
	result = ft_strdup(arg);
	free(arg);
	return (result);
}

char	*ft_handle_pointer(t_sprintf *s)
{
	char	*arg;
	char	*result;

	arg = ft_itoa(va_arg(s->ap, unsigned long));
	if (!arg)
		return (NULL);
	result = ft_strdup(arg);
	free(arg);
	return (result);
}

char	*ft_handle_percent(void)
{
	char	*result;

	result = (char *)malloc(2);
	if (!result)
		return (NULL);
	result[0] = '%';
	result[1] = '\0';
	return (result);
}

char	*ft_append_char(t_sprintf *s, char c)
{
	char	*temp;
	char	*result;

	temp = (char *)malloc(2);
	if (!temp)
		return (NULL);
	temp[0] = c;
	temp[1] = '\0';
	result = ft_strjoin(s->result, temp);
	free(temp);
	return (result);
}
