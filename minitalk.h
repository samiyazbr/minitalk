/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:48:37 by szubair           #+#    #+#             */
/*   Updated: 2022/07/12 12:42:25 by szubair          ###   ########.fr       */
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
void		receive_acknow(int sig);
void		ft_putchar(char c);
void		ft_putnbr(int d);
int			ft_atoi(const char *str);
void		receive_message(int sig);
void		send_messege(char c, int pid);
void		acknow(int *n, int *byte, int *c_end);
int			ft_isalpha(char *c);

#endif
