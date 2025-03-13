/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:37:42 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/12 21:57:12 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(unsigned int num, char signal);

int	ft_puthexa(unsigned int num, char signal)
{
	char	buffer[8];
	int		count;
	int		index;

	count = 0;
	index = 0;
	if (num == 0)
		buffer[index++] = '0';
	while (num > 0)
	{
		if ((num % 16) < 10)
			buffer[index++] = (num % 16) + '0';
		else
		{
			if (signal == 'x')
				buffer[index++] = (num % 16) - 10 + 'a';
			else
				buffer[index++] = (num % 16) - 10 + 'A';
		}
		num /= 16;
	}
	while (--index >= 0)
		count += ft_putchar(buffer[index]);
	return (count);
}
