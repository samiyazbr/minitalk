/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverlib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alal-ali <alal-ali@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:48:28 by alal-ali          #+#    #+#             */
/*   Updated: 2022/05/31 12:26:00 by alal-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	else
		write(1, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int	new_nb;

	if (n == 0)
	{
		ft_putchar(n + 48);
	}
	else if (n > 0)
	{
		new_nb = n / 10;
		if (new_nb != 0)
		{
			ft_putnbr(new_nb);
		}
		ft_putchar(n % 10 + 48);
	}
	else
	{
		ft_putchar('-');
		new_nb = 0 - (n / 10);
		if (new_nb != 0)
		{
			ft_putnbr(new_nb);
		}
		ft_putchar(0 - (n % 10) + 48);
	}
}
