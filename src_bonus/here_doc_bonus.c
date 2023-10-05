/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:58:33 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/11 19:00:26 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	creat_here_doc_file(t_list *strs_holder)
{
	int		fd_in;
	int		infile_flags;
	mode_t	infile_perms;

	infile_flags = O_TRUNC | O_CREAT | O_WRONLY;
	infile_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd_in = open(".heredoc.tmp", infile_flags, infile_perms);
	if (fd_in < 0)
		return (ft_putstr_fd("here_doc", STDERR_FILENO), perror (" "), 0);
	while (strs_holder)
	{
		ft_putstr_fd(strs_holder->content, fd_in);
		free(strs_holder->content);
		strs_holder = strs_holder->next;
	}
	close (fd_in);
	return (1);
}

int	here_doc(char *limiter)
{
	t_list	*strs_holder;
	char	*line;

	strs_holder = NULL;
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, limiter, ft_strlen(limiter))
			&& line[ft_strlen(limiter)] == '\n')
			break ;
		ft_lstadd_back(&strs_holder, ft_lstnew(line));
	}
	if (!creat_here_doc_file(strs_holder))
		return (ft_lstclear(&strs_holder, NULL), 0);
	ft_lstclear(&strs_holder, NULL);
	if (!arrange_input(".heredoc.tmp"))
		return (unlink(".heredoc.tmp"), 0);
	return (1);
}
