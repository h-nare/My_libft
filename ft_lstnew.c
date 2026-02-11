/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:30:11 by narhakob          #+#    #+#             */
/*   Updated: 2026/02/10 11:22:45 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *n = (t_list *)malloc(sizeof(t_list));
    
    n->content = content;
    n->next = NULL;
    return n;
}

// typedef struct node
// {
//     int value;
//     struct node* next;
    
// }node_t;

// void printlist(node_t *head)
// {
//     node_t *temp = head;
    
//     while(temp)
//     {
//         printf("%d - ",temp -> value);
//         temp = temp -> next;
//     }
//     printf("\n");
// }

// node_t *create_new_node(int value)
// {
//     node_t *result = malloc(sizeof(node_t));
//     result -> value = value;
//     result -> next = NULL;
//     return result;
// }

// int main()
// {
//     node_t n1,n2, n3;
//     node_t *head;
    
//     n1.value = 45;
//     n2.value = 8;
//     n3.value = 32;
    
//     head = &n3;
//     n3.next = &n2;
//     n2.next = &n1;
//     n1.next = NULL;//we know where to stop

//     head = head -> next;

//     printlist(head);
    
// }