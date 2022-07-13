/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:55:13 by szubair           #+#    #+#             */
/*   Updated: 2022/07/12 12:34:03 by szubair          ###   ########.fr       */
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
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int d)
{
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (d < 0)
	{
		ft_putchar('-');
		d = -d;
	}
	if (d >= 0 && d <= 9)
		ft_putchar(d + '0');
	if (d > 9)
	{
		ft_putnbr(d / 10);
		ft_putnbr(d % 10);
	}
}

int	ft_isalpha(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
			return (1);
		else
			i++;
	}
	return (0);
}
