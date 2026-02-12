/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:38:10 by narhakob          #+#    #+#             */
/*   Updated: 2026/02/12 23:47:48 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*cp_s1;

	if (!s1 || !s2)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(s2, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(s2, s1[end - 1]))
		end--;
	len = end - start;
	cp_s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!cp_s1)
		return (NULL);
	ft_strlcpy(cp_s1, s1 + start, len + 1);
	return (cp_s1);
}
