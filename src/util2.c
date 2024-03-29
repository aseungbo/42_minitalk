/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:23:48 by seuan             #+#    #+#             */
/*   Updated: 2021/06/19 13:59:53 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || \
			c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *nptr)
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
