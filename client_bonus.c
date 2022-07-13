/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:45:35 by szubair           #+#    #+#             */
/*   Updated: 2022/07/12 12:19:43 by szubair          ###   ########.fr       */
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
		usleep(500);
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
		usleep(500);
			i--;
	}
}

int	check_pid(int pid, char *av)
{
	if (pid <= 0)
	{
		write(1, "invalid pid", 11);
		return (0);
	}
	if (ft_isalpha(av) == 1)
	{
		write(1, "don't put letters with pid", 26);
		return (0);
	}
	return (1);
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
		if (check_pid(pid, av[1]) == 0)
			return (0);
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
