/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alal-ali <alal-ali@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:26:27 by alal-ali          #+#    #+#             */
/*   Updated: 2022/05/31 12:30:45 by alal-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reseive_messege(int sig)
{
	static int	n;
	static int	bit;

	if (sig == SIGUSR1)
	bit += 1 << (7 - n);
	n++;
	if (n == 8)
	{
		ft_putchar(bit);
		n = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_putstr("pid is :");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, reseive_messege);
	signal(SIGUSR2, reseive_messege);
	while (1)
		pause();
}
