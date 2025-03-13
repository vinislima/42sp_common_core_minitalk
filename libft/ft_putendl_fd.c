/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:18:44 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/30 08:47:27 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
		return ;
	count = 0;
	while (s[count] != '\0')
	{
		write(fd, &s[count], 1);
		count++;
	}
	write(fd, "\n", 1);
}
