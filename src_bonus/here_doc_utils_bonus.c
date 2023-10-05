/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:08:38 by eabdelha          #+#    #+#             */
/*   Updated: 2022/02/11 18:57:39 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char	*s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	us1;
	unsigned char	us2;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i] && i < n - 1)
		i++;
	us1 = s1[i];
	us2 = s2[i];
	return ((us1 - us2));
}

t_list	*ft_lstnew(void *content)
{
	t_list	*nel;

	nel = (t_list *)malloc(sizeof (t_list));
	if (nel == NULL)
		return (nel);
	nel->content = content;
	nel->next = NULL;
	return (nel);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst != NULL)
	{
		if (*alst != NULL)
			(ft_lstlast(*alst))->next = new;
		else
			*alst = new;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*hol;

	hol = *lst;
	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			hol = (*lst)->next;
			if (del)
				del((*lst)->content);
			free(*lst);
			*lst = hol;
		}
	}
}
