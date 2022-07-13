/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:45:12 by szubair           #+#    #+#             */
/*   Updated: 2022/07/12 12:20:07 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

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
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (check_pid(pid, av[1]) == 0)
			return (0);
		while (av[2][i] != '\0')
			send_messege(av[2][i++], pid);
		exit(0);
	}
	else
		exit(1);
	return (0);
}
