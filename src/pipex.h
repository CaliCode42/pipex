/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:54:06 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 21:54:06 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "../libft/includes/libft.h"

typedef struct s_fd
{
	int	in;
	int	out;
}		t_fd;

// Error handling
void	error_exit(const char *msg, int exit_code);

// Process handling
void	execute_command(char *cmd, char **env);

// Utility functions
void	free_array(char **array);
char	*get_command_path(char *cmd, char **env);

#endif 