/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:13:04 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/19 19:59:58 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// chamada da biblioteca libft.h para usar as funções de printf e putchar_fd
#include "libft/libft.h"
// chamada da biblioteca types.h para usar o tipo pid_t
#include <sys/types.h>
// chamada da biblioteca unistd.h para usar as funções de kill e sleep
#include <unistd.h>
// chamada da biblioteca stdlib.h para usar a função exit
#include <stdlib.h>
// chamada da biblioteca signal.h para usar os sinais SIGUSR1 e SIGUSR2
#include <signal.h>
// a função init_sig é responsável por inicializar o manipulador de sinais
// ela recebe o sinal e o manipulador de sinais
// e registra o manipulador de sinais para o sinal
void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *))
{
	// struct sigaction é uma estrutura que contém informações sobre o manipulador de sinais
	// ela é usada para registrar o manipulador de sinais
	// e para definir as ações a serem tomadas quando o sinal for recebido
	struct sigaction	susr;
	// a função sigaction é usada para registrar o manipulador de sinais
	// ela recebe o sinal, a estrutura sigaction e um ponteiro para a estrutura sigaction
	// o ponteiro para a estrutura sigaction é usado para retornar as informações
	// sobre o manipulador de sinais anterior
	susr.sa_sigaction = handler;
	// usando a sa_flags para definir as ações a serem tomadas quando o sinal for recebido
	// SA_SIGINFO é usado para indicar que a função de manipulador de sinais
	// receberá um ponteiro para a estrutura siginfo_t
	// SA_RESTART é usado para reiniciar as chamadas de sistema interrompidas pelo sinal
	// SA_NODEFER é usado para permitir que o sinal seja recebido novamente
	// antes que o manipulador de sinais termine
	susr.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	// a função sigemptyset é usada para inicializar o conjunto de sinais
	// ela recebe um ponteiro para o conjunto de sinais
	// e inicializa o conjunto de sinais com o conjunto vazio
	sigemptyset(&susr.sa_mask);
	// é realizada a verificação do sinal onde se o sinal for SIGUSR1
	if (sig == SIGUSR1)
		// a função sigaction é usada para registrar o manipulador de sinais
		// para o sinal SIGUSR1 e o ponteiro para a estrutura sigaction é 0
		// para indicar que não há manipulador de sinais anterior
		sigaction(SIGUSR1, &susr, 0);
	// se o sinal for SIGUSR2
	else if (sig == SIGUSR2)
		// a função sigaction é usada para registrar o manipulador de sinais
		// para o sinal SIGUSR2 e o ponteiro para a estrutura sigaction é 0
		// para indicar que não há manipulador de sinais anterior
		sigaction(SIGUSR2, &susr, 0);
}
// a função sig_usr é o manipulador de sinais
// ela recebe o sinal e o ponteiro para a estrutura siginfo_t
// e o ponteiro para o contexto
void	sig_usr(int sig, siginfo_t *info, void *context)
{
	// declarada uma variável estática para armazenar o caractere
	// declaro e atribuio o valor porque a variáveis estáticas são inicializadas
	// apenas uma vez, e o valor é mantido entre as chamadas da função.
	// caso eu declarece e depois atribuisse o valor, a variável seria inicializada
	// com o valor 0 a cada chamada da função e o valor seria perdido
	static char	c = 0;
	// declara uma variável estática para armazenar o bit que terá o valor de menos um
	// atribuído mostrando que ainda não foi recebido nenhum bit
	static int	bit = -1;
	// a variável context é usada para armazenar o contexto do processo
	// nesse caso declarada para suprimir o aviso de variável não utilizada
	(void)context;
	// a função kill é usada para enviar um sinal para um processo
	// ela recebe o pid do processo e o sinal a ser enviado
	// se o pid for menor que 0, a função retorna -1 e o erro é impresso
	// e o programa é encerrado
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
		// e o caractere é atualizado com o bit
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
