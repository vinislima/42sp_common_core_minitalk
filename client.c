/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:22:27 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/18 20:49:46 by vinda-si         ###   ########.fr       */
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
// a função send_str envia uma string para o servidor
// ela recebe a string e o pid do servidor
// ela envia a string caractere por caractere
// e no final envia o caractere nulo para indicar o fim da string
void	send_str(char *str, pid_t pid)
{
	// variável para controlar o caractere
	int	piece;
	// inicializa o caractere com 0
	piece = 0;
	// enquanto o caractere não for nulo
	// enviar o caractere para o servidor
	while (str[piece])
	{
		// chama a função send_char para enviar o caractere
		// passando o caractere e o pid do servidor
		send_char(str[piece], pid);
		// incrementa o caractere para enviar o próximo
		piece++;
	}
	// após enviar a string, envia o caractere nulo
	// para indicar o fim da string
	send_char(0, pid);
}
// a função sig_usr é o manipulador de sinais
// ela recebe o sinal e verifica qual é o sinal
// se for SIGUSR1, atribui o valor 1 para a variável
// global g_bit_control para indicar que o bit foi recebido
// se for SIGUSR2, sai do programa
// indicando que o servidor terminou
void	sig_usr(int sig)
{
	// verifica qual é o sinal
	// se for SIGUSR1, atribui o valor 1 para a variável
	// global g_bit_control para indicar que o bit foi recebido
	if (sig == SIGUSR1)
		g_bit_control = 1;
	// se for SIGUSR2, sai do programa
	// indicando que o servidor terminou
	else if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}
// na função main iremos fazer a validação dos argumentos
// e chamar as funções para enviar a string para o servidor
// ela recebe os argumentos da linha de comando
int	main(int argc, char **argv)
{
	// pid_t é um tipo de dado para armazenar o pid
	// que é o identificador do processo
	// pid é a variável que irá armazenar o pid do servidor
	pid_t	pid;
	// nesse if é realizada a validação dos argumentos
	// se o número de argumentos for diferente de 3
	// é mostrada uma mensagem de erro e sai do programa
	// e o programa é encerrado
	if (argc != 3)
	{
		ft_printf("Usage: ./client <pid> <string>\n");
		exit(EXIT_FAILURE);
	}
	// é chamada a função signal para registrar o manipulador de sinais
	// de SIGUSR1 e SIGUSR2
	signal(SIGUSR1, &sig_usr);
	signal(SIGUSR2, &sig_usr);
	// converte o primeiro argumento recebido para um inteiro
	// utilizando a função ft_atoi da libft
	pid = ft_atoi(argv[1]);
	// se o pid for não for válido
	// mostra uma mensagem de erro e sai do programa
	if (!pid)
	{
		ft_printf("%s is invalid like pid\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	// caso contrário chama a função send_str
	// para enviar a string para o servidor
	// passando a string e o pid do servidor
	send_str(argv[2], pid);
	// após enviar a string, o programa fica em loop
	// esperando o servidor enviar o sinal de fim
	// para não sobrecarregar o processador
	while (1)
		// usado o sleep para não sobrecarregar o processador
		sleep(1);
}
