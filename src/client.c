/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:07:07 by seuan             #+#    #+#             */
/*   Updated: 2021/06/18 15:55:46 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_sig(int pid, char *string)
{
    int i;

    i = ft_atoi(&string[0]);
    kill(pid, SIGUSR1);
}

int main(int argc, char **argv)
{   
    int     pid;
    int     sig_num;
    char    *string;
    if (argc != 3)
        exit(0);
    pid = ft_atoi(argv[1]);
	string = argv[2];
    send_sig(pid, string);
}