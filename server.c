/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:13:04 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/21 00:49:16 by vinda-si         ###   ########.fr       */
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
	// se o bit for menor que 0 e o caractere for diferente de 0
	// é impresso o caractere e o bit é reiniciado
	if (bit < 0 && !c)
		ft_printf("\nClient say: ");
	// se o bit for somente menor que 0
	// o bit é reiniciado
		if (bit < 0)
		// o bit é reiniciado para o valor de 7
		// para começar a receber os bits
		bit = 8 * sizeof(c) - 1;
	// se o sinal for SIGUSR1
	// o bit é deslocado para a esquerda
	// e o caractere é atualizado com o bit
	if (sig == SIGUSR1)
		// o bit é deslocado para a esquerda
		// e o caractere é atualizado com o bit
		c |= 1 << bit;
	// se o sinal for SIGUSR2
	// o bit é deslocado para a esquerda
	// e o caractere é atualizado com o bit	
	else if (sig == SIGUSR2)
		// o bit é deslocado para a esquerda
		// e o caractere é atualizado com o bit.
		// aqui é aplicado o NOT bit-a-bit (~) e
		// AND bit-a-bit (&=) para manipular os bits
		c &= ~(1 << bit);
	// o simbolo de exclamação é usado para negar o valor
	// transformando o bit em um "bool", sendo 0 para verdadeiro e 1 para falso
	// se o bit for verdadeiro e o caractere for diferente de 0
	// o caractere é impresso	
	if (!bit && c)
		ft_putchar_fd(c, 1);
	// verifica se o bit e o caractere são nulos / valor de zero
	// se forem, o sinal SIGUSR2 é enviado para o processo
	// com o pid recebido dessa forma informando que a mensagem foi recebida
	// e o processo pode enviar a próxima mensagem
	else if (!bit && !c)
		// o sinal SIGUSR2 é enviado para o processo
		// com o pid recebido
		kill(info->si_pid, SIGUSR2);
	// o bit é decrementado
	// para receber o próximo bit		
	bit--;
	// o bit é verificado para saber se foi recebido
	// se não for recebido, o programa fica em loop
	// esperando o bit ser recebido
	kill(info->si_pid, SIGUSR1);
}
// função principal do server
int	main(void)
{
	// a função init_sig é chamada para inicializar o manipulador de sinais
	// para o sinal SIGUSR1 e SIGUSR2
	init_sig(SIGUSR1, &sig_usr);
	init_sig(SIGUSR2, &sig_usr);
	// é impresso o pid do processo
	ft_printf("pid: %d", getpid());
	// o programa fica em loop
	// esperando o sinal ser recebido
	while (1)
		// a função sleep é usada para suspender a execução do programa
		// por um determinado número de segundos
		// nesse caso, o programa é suspenso por um segundo
		// para não sobrecarregar o processador
		sleep(1);
}
