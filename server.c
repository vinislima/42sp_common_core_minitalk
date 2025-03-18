/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:13:04 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/18 17:49:33 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	susr;

	susr.sa_sigaction = handler;
	susr.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&susr.sa_mask);
	if (sig == SIGUSR1)
		sigaction(SIGUSR1, &susr, 0);
	else if (sig == SIGUSR2)
		sigaction(SIGUSR2, &susr, 0);
}

void	sig_usr(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = -1;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		ft_printf("ERROR: can't send sig to pid: %d\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
	if (bit < 0 && !c)
		ft_printf("\nClient say: ");
	if (bit < 0)
		bit = 8 * sizeof(c) - 1;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	else if (sig == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		ft_putchar_fd(c, 1);
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	init_sig(SIGUSR1, &sig_usr);
	init_sig(SIGUSR2, &sig_usr);
	ft_printf("pid: %d", getpid());
	while (1)
		sleep(1);
}
