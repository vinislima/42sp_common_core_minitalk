/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:45:52 by vinda-si          #+#    #+#             */
/*   Updated: 2024/10/28 15:07:55 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr);

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	count;

	result = 0;
	count = 0;
	sign = 1;
	while (nptr[count] == ' '
		|| nptr[count] == '\t' || nptr[count] == '\n'
		|| nptr[count] == '\r' || nptr[count] == '\v'
		|| nptr[count] == '\f')
			count++;
	if (nptr[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (nptr[count] == '+')
		count++;
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		result = result * 10 + (nptr[count] - '0');
		count++;
	}
	return (sign * result);
}
