/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alal-ali <alal-ali@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:23:12 by alal-ali          #+#    #+#             */
/*   Updated: 2022/05/31 12:26:35 by alal-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

size_t		ft_strlen(const char *s);
void		ft_putstr(char *string);
void		ft_putchar(char c);
void		ft_putnbr(int num);
int			ft_atoi(const char *str);
void		reseive_messege(int sig);
void		send_messege(char c, int pid);

#endif
