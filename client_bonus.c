/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:45:35 by szubair           #+#    #+#             */
/*   Updated: 2022/06/27 10:46:37 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	receive_acknow(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("i have received\n");
	exit(0);
}

void	send_messege(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
			i--;
	}
}

void	send_pid(int c_pid, int pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (c_pid >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
			i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	int		client_pid;

	if (ac == 3)
	{
		i = 0;
		client_pid = getpid();
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, receive_acknow);
		while (av[2][i] != '\0')
			send_messege(av[2][i++], pid);
		if (av[2][i] == '\0')
		{
			send_messege(-1, pid);
			send_pid(client_pid, pid);
		}
	}
	else
		exit(1);
	return (0);
}
