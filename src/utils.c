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

void	init_pipex_data(t_pipex_data *data, char **av, char **env)
{
	data->pid1 = 0;
	data->pid2 = 0;
	data->cmd1 = av[2];
	data->cmd2 = av[3];
	data->envp = env;
	data->file1 = av[1];
	data->file2 = av[4];
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	*ft_str_threejoin(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	len3;
	size_t	total_len;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	total_len = len1 + len2 + len3 + 1;
	str = (char *)malloc(sizeof(char) * total_len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, total_len);
	ft_strlcat(str, s2, total_len);
	ft_strlcat(str, s3, total_len);
	return (str);
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
		bin = ft_str_threejoin(dir, "/", cmd);
		if (!bin)
			return (NULL);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
	}
	return (cmd);
}
