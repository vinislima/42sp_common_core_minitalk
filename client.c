/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:22:27 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/18 19:02:03 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// chamada da biblioteca libft.h para usar as funções de printf e atoi
#include "libft/libft.h"
// chamada da biblioteca types.h para usar o tipo pid_t
#include <sys/types.h>
// chamada da biblioteca unistd.h para usar as funções de kill e usleep
#include <unistd.h>
// chamada da biblioteca stdlib.h para usar a função exit
#include <stdlib.h>
// chamada da biblioteca signal.h para usar os sinais SIGUSR1 e SIGUSR2
#include <signal.h>

// variável global para controlar o bit
int	g_bit_control;
// função para enviar um caractere para o servidor
// ela recebe o caractere e o pid do servidor
void	send_char(char c, pid_t pid)
{
	// variável para controlar o bit
	int	bit;
	// inicializa o bit com o valor 8 * sizeof(c) - 1
	// fazendo isso é acessado o último bit do caractere
	// sendo o mais significativo
	bit = 8 * sizeof(c) - 1;
	// enquanto o bit for maior ou igual a 0
	// esse loop vai enviar o caractere bit a bit
	while (bit >= 0)
	{
		// se o pid não for válido
		// mostra uma mensagem de erro e sai do programa
		if (kill(pid, 0) < 0)
		{
			ft_printf("ERROR: can't talk with the pid: %d\n", pid);
			exit(EXIT_FAILURE);
		}
		// caso o pid seja válido
		// é atribuído o valor 0 para a variável global g_bit_control
		// para controlar o bit
		g_bit_control = 0;
		// se o bit do caractere for 1
		// envia o sinal SIGUSR1 para o servidor
		// caso contrário, envia o sinal SIGUSR2
		if (c & (1 << bit))
			// o SIGUSR1 é enviado para o servidor
			// representando o bit 1
			kill(pid, SIGUSR1);
		else
			// o SIGUSR2 é enviado para o servidor
			// representando o bit 0
			kill(pid, SIGUSR2);
		// após isso o bit é decrementado	
		bit--;
		// é verificado se o bit foi recebido
		// se não for recebido, o programa fica em loop
		// esperando o bit ser recebido
		while (g_bit_control != 1)
			// usado o sleep para não sobrecarregar o processador
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
