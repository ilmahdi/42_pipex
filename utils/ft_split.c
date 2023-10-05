/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:14:59 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/08 10:15:01 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_man/pipex.h"

static void	ft_fil_strs(char const *s, char *strs, int fi, int li)
{
	int	j;

	j = 0;
	while (fi < li)
		strs[j++] = s[fi++];
	strs[j] = '\0';
}

static	int	ft_switch(char const *s, char **strs, int aut, char c)
{
	int	i;
	int	j;
	int	fi;

	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		fi = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (aut < 0 && fi != i)
		{
			strs[++j] = (char *)malloc(sizeof(char) * (i - fi + 1));
			if (strs[j] == NULL)
				return (-2);
			ft_fil_strs(s, strs[j], fi, i);
		}
		if (aut >= 0 && fi != i)
			aut++;
	}
	return (aut);
}

char	**ft_split(char const *s, char c, t_collect *var)
{
	char	**strs;
	int		cmp;

	cmp = 0;
	strs = NULL;
	if (!s)
		return (0);
	cmp = ft_switch(s, strs, 0, c);
	strs = (char **)malloc(sizeof(char *) * (cmp + 1));
	if (strs == NULL)
		return (NULL);
	strs[cmp] = NULL;
	cmp = ft_switch(s, strs, -1, c);
	if (cmp == -2)
		return (free_2d(strs), exit_error(var, MEM_ERROR), NULL);
	return (strs);
}
