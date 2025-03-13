/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:56:20 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/30 12:01:54 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *c);

size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	while (c[count] != '\0')
	{
		count++;
	}
	return (count);
}
