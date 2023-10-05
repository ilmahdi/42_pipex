/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:13:32 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 10:13:36 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>

# define MEM_ERROR "Memory error has been detected"
# define CMD_ERROR ": command not found"
# define ARGS_ERROR "Error : Invalid number of arguments."

typedef struct s_collect
{
	char	**cmd;
	char	*slash_cmd;
	char	**paths;
}	t_collect;

void	execute_cmd(char *av, char **envp);
void	arrange_output(char *outfile);
int		arrange_input(char *infile);

void	exit_error(t_collect *var, char *msg);
void	free_res(t_collect *var);
void	free_2d(char **strs);

void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c, t_collect *var);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
