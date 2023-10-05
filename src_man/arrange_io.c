/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:13:59 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/11 18:48:27 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	arrange_input(char *infile)
{
	int	fd_in;
	int	in_err;

	in_err = 1;
	fd_in = open(infile, O_RDONLY);
	if (fd_in < 0)
	{
		in_err = 0;
		ft_putstr_fd(infile, STDERR_FILENO);
		perror (" ");
	}
	else
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	return (in_err);
}

void	arrange_output(char *outfile)
{
	int		fd_out;
	int		outfile_flags;
	mode_t	outfile_perms;

	outfile_flags = O_TRUNC | O_CREAT | O_WRONLY;
	outfile_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd_out = open(outfile, outfile_flags, outfile_perms);
	if (fd_out < 0)
	{
		ft_putstr_fd(outfile, STDERR_FILENO);
		perror (" ");
		exit(1);
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
}
