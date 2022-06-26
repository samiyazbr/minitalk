/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:50:53 by szubair           #+#    #+#             */
/*   Updated: 2022/06/26 16:18:11 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_ack(int c_pid)
{
	kill(c_pid, SIGUSR1);
	return (0);
}

void	receive_message(int sig)
{
	static int	n;
	static int	byte;
	static int	c_end;

	if (c_end == 0 && sig == SIGUSR1)
		byte |= 1 << (7 - n);
	if (c_end == 0 && sig == SIGUSR2)
		byte |= 0 << (7 - n);
	if (c_end == 1 && sig == SIGUSR1)
		byte |= 1 << (31 - n);
	if (c_end == 1 && sig == SIGUSR2)
		byte |= 0 << (31 - n);
	n++;
	if (c_end == 0 && n == 8 && (char)byte == -1)
		c_end = 1;
	else if (c_end == 0 && n == 8)
		ft_putchar(byte);
	else if (c_end == 1 && n == 32)
		c_end = send_ack(byte);
	if ((c_end == 1 && n == 32) || (c_end == 0 && n == 8))
	{	
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
