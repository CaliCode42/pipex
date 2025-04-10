/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:49:44 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 20:49:44 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <stdarg.h>

char	*ft_append_formatted(t_sprintf *s, char *formatted)
{
	char	*temp;
	char	*result;

	temp = s->result;
	result = ft_strjoin(s->result, formatted);
	free(temp);
	free(formatted);
	return (result);
}

char	*ft_process_format_part1(t_sprintf *s, int *i)
{
	char	*formatted;

	formatted = ft_handle_format(s, i);
	if (!formatted)
	{
		free(s->result);
		return (NULL);
	}
	s->result = ft_append_formatted(s, formatted);
	if (!s->result)
		return (NULL);
	return (s->result);
}

char	*ft_process_format_part2(t_sprintf *s, int i)
{
	s->result = ft_append_char(s, s->format[i]);
	if (!s->result)
		return (NULL);
	return (s->result);
}

char	*ft_process_format(t_sprintf *s)
{
	int		i;

	s->result = ft_strdup("");
	if (!s->result)
		return (NULL);
	i = 0;
	while (s->format[i])
	{
		if (s->format[i] == '%')
		{
			if (!ft_process_format_part1(s, &i))
				return (NULL);
		}
		else
		{
			if (!ft_process_format_part2(s, i))
				return (NULL);
		}
		i++;
	}
	return (s->result);
}
