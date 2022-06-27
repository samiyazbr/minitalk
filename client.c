/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:45:12 by szubair           #+#    #+#             */
/*   Updated: 2022/06/26 15:45:12 by szubair          ###   ########.fr       */
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
		usleep(100);
			i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		while (av[2][i] != '\0')
			send_messege(av[2][i++], pid);
		exit(0);
	}
	else
		exit(1);
	return (0);
}
