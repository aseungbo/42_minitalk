/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:06:52 by seuan             #+#    #+#             */
/*   Updated: 2021/06/18 15:57:28 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_pid(void)
{
    int pid;
    char *str;
    
    pid = getpid();
    if(!(str = ft_itoa(pid)))
        exit(0);
    ft_putstr_fd(str, 1);
    write(1, "\n", 1);
    free(str);
}

void sig_usr(int sign)
{
        if(sign == SIGUSR1)
                printf("received SIGUSR1\n");
        else if(sign == SIGUSR2)
                printf("received SIGUSR2\n");
}

int main(void)
{
    print_pid();
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
    while (1)
        pause();
}