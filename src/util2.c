/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:23:48 by seuan             #+#    #+#             */
/*   Updated: 2021/06/18 15:38:35 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// char		*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		idx;
// 	int		s1_len;
// 	int		s2_len;
// 	char	*res;

// 	if (s1 && s2)
// 	{
// 		s1_len = ft_strlen(s1);
// 		s2_len = ft_strlen(s2);
// 		res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
// 		if (!res)
// 			return (NULL);
// 		idx = -1;
// 		while (s1[++idx])
// 			res[idx] = s1[idx];
// 		idx = -1;
// 		while (s2[++idx])
// 		{
// 			res[s1_len] = s2[idx];
// 			s1_len++;
// 		}
// 		res[s1_len] = '\0';
// 		return (res);
// 	}
// 	return (NULL);
// }

// size_t	ft_strlcpy(char *dst, char *src, size_t size)
// {
// 	size_t idx;

// 	idx = 0;
// 	if (!dst || !src)
// 		return (0);
// 	if (!size)
// 		return (ft_strlen(src));
// 	while (src[idx] && idx < size - 1)
// 	{
// 		dst[idx] = src[idx];
// 		idx++;
// 	}
// 	dst[idx] = '\0';
// 	return (ft_strlen(src));
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t idx;

// 	idx = 0;
// 	while (s[idx])
// 		idx++;
// 	return (idx);
// }

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || \
			c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *nptr)
{
	long	nbr;
	long	minus;
	int		idx;

	nbr = 0;
	minus = 1;
	idx = 0;
	while (ft_isspace(nptr[idx]) && nptr[idx] != '\0')
		idx++;
	if (nptr[idx] == '-')
		minus = -1;
	if (nptr[idx] == '+' || nptr[idx] == '-')
		idx++;
	while (nptr[idx] != '\0' && ('0' <= nptr[idx] && nptr[idx] <= '9'))
	{
		nbr = (nbr * 10) + (nptr[idx] - '0');
		if (nbr > 2147483647 && minus == 1)
			return (-1);
		if (nbr > 2147483648 && minus == -1)
			return (0);
		idx++;
	}
	return (minus * nbr);
}