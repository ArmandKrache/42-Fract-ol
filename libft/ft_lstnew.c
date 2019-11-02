/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:09:47 by akrache           #+#    #+#             */
/*   Updated: 2018/11/15 14:19:13 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;
	void	*tmp;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		if (!(tmp = (void *)malloc(content_size)))
			return (NULL);
		ft_bzero(tmp, content_size);
		ft_memcpy(tmp, content, content_size);
		res->content = tmp;
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
