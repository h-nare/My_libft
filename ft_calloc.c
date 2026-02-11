/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:33:07 by narehakobya       #+#    #+#             */
/*   Updated: 2026/02/10 21:11:51 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
    void *arr;
	
    if (nmemb != 0 && size > SIZE_MAX / nmemb)
        return (NULL);

    arr = malloc(nmemb * size);
    if (!arr)
        return (NULL);

    if (nmemb * size > 0)
        ft_bzero(arr, nmemb * size);

    return (arr);
}
