/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:22:27 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/19 21:17:02 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	g_bit_control;

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = 8 * sizeof(c) - 1;
	while (bit >= 0)
	{
		if (kill(pid, 0) < 0)
		{
			ft_printf("ERROR: can't talk with the pid: %d\n", pid);
			exit(EXIT_FAILURE);
		}
		g_bit_control = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_bit_control != 1)
			usleep(10);
	}
}

void	send_str(char *str, pid_t pid)
{
	int	piece;

	piece = 0;
	while (str[piece])
	{
		send_char(str[piece], pid);
		piece++;
	}
	send_char(0, pid);
}

void	sig_usr(int sig)
{
	if (sig == SIGUSR1)
		g_bit_control = 1;
	else if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <pid> <string>\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &sig_usr);
	signal(SIGUSR2, &sig_usr);
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("%s is invalid like pid\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	send_str(argv[2], pid);
	while (1)
		sleep(1);
}
