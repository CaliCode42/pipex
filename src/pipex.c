/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:50:41 by tcali             #+#    #+#             */
/*   Updated: 2025/04/11 00:12:01 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//How does exit work???
void	error_exit(const char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

void	execute_command(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
		error_exit("Error splitting command", 1);
	path = get_command_path(args[0], env);
	if (!path)
	{
		free_array(args);
		error_exit("Command not found", 127);
	}
	if (execve(path, args, env) == -1)
	{
		if (path != args[0])
			free(path);
		free_array(args);
		error_exit("Error executing command", 1);
	}
}

void	child(int pipe_fd[2], t_pipex_data *data, int is_first)
{
	int	fd;

	if (is_first)
	{
		fd = open(data->file1, O_RDONLY);
		if (fd < 0)
			error_exit("Error opening input file", 1);
		dup2(fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(fd);
		execute_command(data->cmd1, data->envp);
	}
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		fd = open(data->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			error_exit("Error opening output file", 1);
		dup2(fd, STDOUT_FILENO);
		close(pipe_fd[1]);
		close(fd);
		execute_command(data->cmd2, data->envp);
	}
}

void	parent(int pipe_fd[2], t_pipex_data *data)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex_data	data;

	if (ac != 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2", 1);
	init_pipex_data(&data, av, envp);
	if (pipe(data.pipe_fd) < 0)
		error_exit("Error creating pipe", 1);
	data.pid1 = fork();
	if (data.pid1 < 0)
		error_exit("Error forking first process", 1);
	if (data.pid1 == 0)
		child(data.pipe_fd, &data, 1);
	data.pid2 = fork();
	if (data.pid2 < 0)
		error_exit("Error forking second process", 1);
	if (data.pid2 == 0)
		child(data.pipe_fd, &data, 0);
	parent(data.pipe_fd, &data);
	free_pipex_data(&data);
	return (0);
}
