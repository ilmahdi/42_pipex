/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:14:22 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 10:14:24 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])
	{
		free(strs[i]);
		strs[i] = NULL;
	}
	free(strs);
	strs = NULL;
}

void	exit_error(t_collect *var, char *msg)
{
	free_res(var);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit (127);
}

void	free_res(t_collect *var)
{
	free_2d(var->cmd);
	free_2d(var->paths);
	free(var->slash_cmd);
	var->slash_cmd = NULL;
}
