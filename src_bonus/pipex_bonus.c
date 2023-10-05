/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:24:44 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/09 16:27:09 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_error(char *cmd, char **envp)
{
	char	**paths;
	char	**args;
	char	*full_cmd;
	char	*slash_cmd;
	int		i;

	if (!access(cmd, F_OK))
		return (1);
	i = 0;
	args = ft_split(cmd, ' ', NULL);
	cmd = args[0];
	slash_cmd = ft_strjoin("/", cmd);
	free_2d(args);
	paths = ft_split(&(envp[get_path(envp)][5]), ':', NULL);
	while (paths && paths[i])
	{
		full_cmd = ft_strjoin(paths[i], slash_cmd);
		if (!access(full_cmd, F_OK))
			return (free(full_cmd), free(slash_cmd), free_2d(paths), 1);
		free(full_cmd);
		i++;
	}
	return (free(slash_cmd), free_2d(paths), 0);
}

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
		if (in_err == 1)
			exit(1);
		execute_cmd(av, envp);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	if (!check_error(av, envp))
		waitpid(pid_child, NULL, 0);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	in_err;
	int	remove_heredoc;

	if (ac < 5)
		return (ft_putendl_fd(ARGS_ERROR, STDERR_FILENO), 1);
	i = 1;
	remove_heredoc = 0;
	if (!ft_strncmp(av[1], "here_doc", 8) && i++)
	{
		in_err = here_doc(av[2]);
		if (in_err)
			remove_heredoc = 1;
	}
	else
		in_err = arrange_input(av[1]);
	arrange_output(av[ac - 1]);
	while (++i < (ac - 2) && ++in_err)
		if (!fork_proc(av[i], envp, in_err))
			return (1);
	if (remove_heredoc)
		unlink(".heredoc.tmp");
	execute_cmd(av[i], envp);
	return (1);
}
