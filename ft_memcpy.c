/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narhakob <narhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:22:39 by narehakobya       #+#    #+#             */
/*   Updated: 2026/01/31 17:56:55 by narhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ds;
	const unsigned char	*fsrc;

	ds = (unsigned char *)dest;
	fsrc = (const unsigned char *)src;
	while (n--)
	{
		*ds = *fsrc;
		ds++;
		fsrc++;
	}
	return (dest);
}
