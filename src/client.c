/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:07:07 by seuan             #+#    #+#             */
/*   Updated: 2021/06/19 14:04:49 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void		end_checker(int pid)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(50);
	}
}

char		*char_to_bit(char c)
{
	int		i;
	char	*str;

	if (!(str = malloc(sizeof(8))))
		exit(0);
	str[7] = 0;
	i = 6;
	while (c > 1)
	{
		str[i] = (c % 2) + 48;
		c /= 2;
		i--;
	}
	str[i] = (c % 2) + 48;
	i--;
	while (i >= 0)
		str[i--] = 48;
	return (str);
}

void		send_sig(int pid, char *string)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (string[i])
	{
		if (!(tmp = char_to_bit(string[i])))
			exit(0);
		j = 0;
		while (tmp[j])
		{
			if (tmp[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(50);
		}
		free(tmp);
		i++;
	}
	end_checker(pid);
}

int			main(int argc, char **argv)
{
	int		pid;
	char	*string;

	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	string = argv[2];
	send_sig(pid, string);
}
