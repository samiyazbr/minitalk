/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:55:13 by szubair           #+#    #+#             */
/*   Updated: 2022/06/27 10:48:35 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * n);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
