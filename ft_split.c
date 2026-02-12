/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:00:59 by narhakob          #+#    #+#             */
/*   Updated: 2026/02/12 23:44:11 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int ft_len_of_arr(char const *s, char c)
// {
//     int i;
//     int len;

//     i = 0;
//     len = 0;
//     while(s[i] && s[i] == c)
//     {
//         i++;
//     }
//     while(s[i])
//     {
//         while(s[i] == c)
//         {
//             if (s[i + 1] && s[i + 1] == c)
//             break ;
//         i++;
//     }
//     if (s[i] && s[i - 1] == c)
//         len++;
//         i++;
//     }
//     return (len); 
// }


// char **ft_split(char const *s, char c)
// {
//     char **arr;
//     int length;
//     int i;
//     int k;

//     i = 0;
//     k = 0;
//     length = ft_len_of_arr(s,c);
//     arr = (char *)malloc((length + 1) * sizeof(char));
//     if (!arr)
//         return (NULL);
//     while(s[i])
//     {
//         while(s[i] == c)
//         {
//             i++;
//         }

//     }
// }

// int main()
// {
//     char s[] = ",,,,af,,,da";
//     char c = ',';
    
//     printf("%d\n", ft_len_of_arr(s,c));
// }

static int	ft_count_words(const char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			words++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static char	**ft_malloc_strs(char **strs, const char *s, char c)
{
	int	count;
	int	i;
	int	x;

	count = 0;
	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		if ((s[i] == c && i > 0 && s[i - 1] != c)
			|| (s[i] != c && s[i + 1] == '\0'))
		{
			strs[x] = malloc(sizeof(char) * (count + 1));
			if (!strs[x])
				return (NULL);
			count = 0;
			x++;
		}
		i++;
	}
	return (strs);
}

static char	**ft_cpy_strs(char **strs, const char *s, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
			strs[x][y++] = s[i];
		if (s[i] != c && s[i + 1] == '\0')
			strs[x][y] = '\0';
		if (s[i] == c && i > 0 && s[i - 1] != c)
		{
			strs[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	return (strs);
}

static char	**ft_merror(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		wordcount;

	if (!s)
	{
		strs = malloc(sizeof(char *));
		if (!strs)
			return (NULL);
		*strs = NULL;
		return (strs);
	}
	wordcount = ft_count_words(s, c);
	strs = malloc(sizeof(*strs) * (wordcount + 1));
	if (!strs)
		return (NULL);
	if (ft_malloc_strs(strs, s, c))
	{
		ft_cpy_strs(strs, s, c);
		strs[wordcount] = NULL;
	}
	else
		strs = ft_merror(strs);
	return (strs);
}