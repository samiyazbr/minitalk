/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:50:04 by szubair           #+#    #+#             */
/*   Updated: 2022/06/26 15:50:35 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_message(int sig)
{
	static int	n;
	static int	byte;

	if (sig == SIGUSR1)
		byte += 1 << (7 - n);
	if (sig == SIGUSR2)
		byte += 0 << (7 - n);
	n++;
	if (n == 8)
	{
		ft_putchar(byte);
		n = 0;
		byte = 0;
	}
}

int	main(void)
{
	ft_putstr("pid is :");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, receive_message);
	signal(SIGUSR2, receive_message);
	while (1)
		pause();
}
