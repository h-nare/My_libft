/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narhakob <narhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:29:48 by narehakobya       #+#    #+#             */
/*   Updated: 2026/01/31 17:59:45 by narhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;

	if (!dest && !src)
		return (NULL);
	cdest = (unsigned char *)dest;
	csrc = (const unsigned char *)src;
	if (cdest > csrc)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	else
	{
		while (n--)
			*cdest++ = *csrc++;
	}
	return (dest);
}
