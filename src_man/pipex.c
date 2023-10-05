/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:13:48 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/11 18:51:20 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fork_proc(char *av, char **envp, int in_err)
{
	int		fd[2];
	pid_t	pid_child;

	if (pipe(fd) != 0)
		return (perror("pipe"), 0);
	pid_child = fork();
	if (pid_child == -1)
		return (perror("fork"), 0);
	else if (!pid_child)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (in_err == 0)
			exit(1);
		execute_cmd(av, envp);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int	in_err;

	if (ac != 5)
		return (ft_putendl_fd(ARGS_ERROR, STDERR_FILENO), 1);
	in_err = arrange_input(av[1]);
	arrange_output(av[ac - 1]);
	if (!fork_proc(av[2], envp, in_err))
		return (1);
	execute_cmd(av[3], envp);
	return (1);
}
