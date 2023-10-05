/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:14:12 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/12 14:43:15 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			return (i);
		i++;
	}
	return (0);
}

char	*check_cmd(t_collect *var, char **envp)
{
	char	*full_cmd;
	int		i;

	if (!access(var->cmd[0], F_OK | X_OK))
		return (var->cmd[0]);
	i = 0;
	var->slash_cmd = ft_strjoin("/", var->cmd[0]);
	if (!var->slash_cmd)
		exit_error(var, MEM_ERROR);
	var->paths = ft_split(&(envp[get_path(envp)][5]), ':', var);
	while (var->paths[i])
	{
		full_cmd = ft_strjoin(var->paths[i], var->slash_cmd);
		if (!full_cmd)
			exit_error(var, MEM_ERROR);
		if (!access(full_cmd, F_OK))
			return (full_cmd);
		free(full_cmd);
		i++;
	}
	return (NULL);
}

void	execute_cmd(char *av, char **envp)
{
	t_collect	var;
	char		*hol;

	var = (t_collect){};
	var.cmd = ft_split(av, ' ', &var);
	hol = var.cmd[0];
	var.cmd[0] = check_cmd(&var, envp);
	if (!var.cmd[0])
	{
		ft_putstr_fd(hol, STDERR_FILENO);
		free(hol);
		exit_error(&var, CMD_ERROR);
	}
	execve(var.cmd[0], var.cmd, envp);
	ft_putstr_fd(hol, STDERR_FILENO);
	if (hol != var.cmd[0])
		free(hol);
	free_res(&var);
	perror (" ");
	exit(127);
}
