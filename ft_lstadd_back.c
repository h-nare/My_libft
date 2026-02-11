/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:43:15 by narhakob          #+#    #+#             */
/*   Updated: 2026/02/11 17:20:32 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{ 
    t_list *tmp;
    
    if(!new || !lst)
        return ;
    if(!*lst)
        *lst = new;
        return ;
    tmp = ft_lstlast(*lst);
    tmp->next = new;
}