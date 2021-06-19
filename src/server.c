/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:06:52 by seuan             #+#    #+#             */
/*   Updated: 2021/06/19 14:01:53 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void			print_pid(void)
{
	int			pid;
	char		*str;

	pid = getpid();
	if (!(str = ft_itoa(pid)))
		exit(0);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	free(str);
}

void			sig_handler(int sign)
{
	static int	cnt;
	static int	c_bit;

	cnt++;
	if (sign == SIGUSR2)
	{
		c_bit = c_bit << 1;
		c_bit += 1;
	}
	else
		c_bit = c_bit << 1;
	if (cnt == 7)
	{
		if (c_bit == 0)
			ft_putchar_fd('\n', 1);
		ft_putchar_fd(c_bit, 1);
		c_bit = 0;
		cnt = 0;
	}
}

int				main(void)
{
	print_pid();
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
