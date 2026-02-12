/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:12:15 by narhakob          #+#    #+#             */
/*   Updated: 2026/02/12 23:26:52 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int ft_len_of_str(int n, char *str)
// {
//     size_t len;

//     len = 0;
//     if(n == 1)
//         return (1);
//     if(n < 0)
//     {
//         len++;
//         n = -n;
//     }
//     while(n >= 1)
//     {
//         len++;
//         n = n/10;
//     }
//     return (len);
// }

// char *ft_it_to_str(int n, char *str,size_t length)
// {
//     if(n < 0)
//     {
//         str[0] = '-';
//         n = -n;
//     }
//     str = (char *)malloc((length + 1) * sizeof(char));
//     length--;
//     while(length > 0)
//     {
//         str[length] = (n % 10) + '0';
//         n = n/10;
//         length--;            
//     }
//     if(str[0] != '-')
//     {
//         str[0] = (n % 10) + '0';
//     }
//     return (str);
// }
// char *ft_itoa(int n)
// {
//     char *str;
//     int length;

//     length = ft_len_of_str(n,str);  
//     str = ft_it_to_str(n,str,length);
//     if(!str)
//         return (NULL);
//     return (str);
// }

// int main()
// {
//     int n = 1243;
//     printf("%s\n",ft_itoa(n));
// }

static int	ft_len_of_str(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_it_to_str(int n, size_t length)
{
	char	*str;
	int		is_neg;

	is_neg = 0;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		is_neg = 1;
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--length] = (n % 10) + '0';
		n = n / 10;
	}
	if (!is_neg)
		str[0] = (n % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	length = ft_len_of_str(n);
	str = ft_it_to_str(n, length);
	return (str);
}