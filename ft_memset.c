/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narhakob <narhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:34:17 by narhakob          #+#    #+#             */
/*   Updated: 2026/01/31 18:00:29 by narhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*start;
	unsigned char	ch;

	ch = (unsigned char)c;
	start = (unsigned char *)b;
	while (len--)
	{
		*start = ch;
		start++;
	}
	return (b);
}
