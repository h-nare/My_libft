/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:42:49 by narhakob          #+#    #+#             */
/*   Updated: 2026/02/10 11:26:07 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    t_list *new_list;
    t_list *new_node;

    new_list = NULL;
    if(!lst || !f)
        return (NULL);
    
    while(lst)
    {
        new_node = ft_lstnew(f(lst->content));
        if(!new_node)
        {
            ft_lstclear(&new_list,del);
        }
        ft_lstadd_back(&new_list, new_node);
        lst = lst -> next;
    }
    return (new_list);
}

