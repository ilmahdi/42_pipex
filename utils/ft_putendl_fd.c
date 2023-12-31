/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:14:43 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 10:14:45 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_man/pipex.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (s != NULL)
	{
		while (s[++i])
			write (fd, &s[i], 1);
		write (fd, "\n", 1);
	}
}
