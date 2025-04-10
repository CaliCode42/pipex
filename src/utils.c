/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:48:52 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 20:48:52 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	*get_command_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;

	while (path && *path)
	{
		dir = ft_strsep(&path, ":");
		bin = malloc(ft_strlen(dir) + ft_strlen(cmd) + 2);
		if (!bin)
			return (NULL);
		ft_snprintf(bin, sizeof(bin), "%s/%s", dir, cmd);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
	}
	return (cmd);
}
