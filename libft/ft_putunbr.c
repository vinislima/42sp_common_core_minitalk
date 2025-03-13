/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:30:28 by vinda-si          #+#    #+#             */
/*   Updated: 2025/03/12 21:56:48 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int num);

int	ft_putunbr(unsigned int num)
{
	char	buffer[10];
	int		count;
	int		index;

	count = 0;
	index = 0;
	if (num == 0)
		buffer[index++] = '0';
	while (num > 0)
	{
		buffer[index++] = (num % 10) + '0';
		num /= 10;
	}
	while (--index >= 0)
		count += ft_putchar(buffer[index]);
	return (count);
}
