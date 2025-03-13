/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:21:06 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/30 08:44:13 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	if (s == NULL || f == NULL)
		return ;
	count = 0;
	while (s[count] != '\0')
	{
		f(count, &s[count]);
		count++;
	}
}
