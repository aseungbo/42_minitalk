/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:06:52 by seuan             #+#    #+#             */
/*   Updated: 2021/06/18 22:27:07 by seuan            ###   ########.fr       */
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

char	*ft_create_string(char carattere, char *string)
{
	char	*temp;
	char	*temp2;

	temp = malloc(2);
	if (temp == 0)
		exit(0);
	temp[0] = carattere;
	temp[1] = 0;
	if (string == 0)
	{
		string = malloc(2);
		if (string == 0)
			exit(0);
		ft_strlcpy(string, temp, 2);
	}
	else
	{
		temp2 = string;
		string = ft_strjoin(string, temp);
		if (string == 0)
			exit (0);
		free(temp2);
	}
	free(temp);
	return (string);
}

void sig_usr(int sign)
{
	static int	cnt;
	static int	c_bit;
	static char	*string;

	cnt++;
	if (sign == SIGUSR2)
	{
		c_bit = c_bit << 1;
		c_bit += 1;
	}
	else
		c_bit = c_bit << 1;
    printf("sign: %d \n", sign);
    if (cnt == 7)
    
	{
		string = ft_create_string(c_bit, string);
		if (c_bit == 0)
		{
			ft_putstr_fd(string, 1);
			write(1, "\n", 1);
			free(string);
			string = 0;
		}
		cnt = 0;
		c_bit = 0;
	}
}


int main(void)
{
    print_pid();
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
    while (1)
        pause();
}