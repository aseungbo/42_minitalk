/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:54:01 by seuan             #+#    #+#             */
/*   Updated: 2021/06/18 21:27:15 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

// Delete header for test
# include <stdio.h>

// util.c
char	*positive_num(int n, int n_cnt);
int		num_counter(int n);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);

#endif