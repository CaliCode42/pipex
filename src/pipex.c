/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:50:41 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 22:21:27 by tcali            ###   ########.fr       */
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

void	child(int pipe_fd[2], t_fd fd, char *cmd, char **envp)
{
	dup2(fd.in, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(fd.in);
	close(fd.out);
	execute_command(cmd, envp);
}

void	parent(int pipe_fd[2], t_fd fd, pid_t pid1, pid_t pid2)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd.in);
	close(fd.out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_fd	fd;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2", 1);
	fd.in = open(av[1], O_RDONLY);
	if (fd.in < 0)
		error_exit("Error opening input file", 1);
	fd.out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd.out < 0)
	{
		close(fd.in);
		error_exit("Error opening output file", 1);
	}
	if (pipe(pipe_fd) < 0)
	{
		close(fd.in);
		close(fd.out);
		error_exit("Error creating pipe", 1);
	}
	pid1 = fork();
	if (pid1 < 0)
		error_exit("Error forking first process", 1);
	if (pid1 == 0)
		child(pipe_fd, fd, av[2], envp);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("Error forking second process", 1);
	if (pid2 == 0)
		child(pipe_fd, fd, av[3], envp);
	parent(pipe_fd, fd, pid1, pid2);
	return (0);
}
