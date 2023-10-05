/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:27:41 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/12 14:41:52 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include "../get_next_line/get_next_line.h"

# define CMD_ERROR ": command not found"
# define MEM_ERROR "Memory error has been detected"
# define ARGS_ERROR "Error : Invalid number of arguments."

typedef struct s_collect
{
	char	**cmd;
	char	*slash_cmd;
	char	**paths;
}	t_collect;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int		get_path(char **envp);
void	execute_cmd(char *av, char **envp);
void	arrange_output(char *outfile);
int		arrange_input(char *infile);

int		ft_strncmp(const char	*s1, const char *s2, size_t n);
int		here_doc(char *limiter);

void	exit_error(t_collect *var, char *msg);
void	free_res(t_collect *var);
void	free_2d(char **strs);

void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c, t_collect *var);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));

#endif
