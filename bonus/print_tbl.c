/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:08:57 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 11:26:36 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "towerdoku.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i += ft_putchar_fd(str[i], fd);
	return (i);
}

void	print_tbl(t_tdk *tdk)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < tdk->size + 2)
	{
		j = -1;
		while (++j < tdk->size + 2)
		{
			if (i == 0 || i == tdk->size + 1 || j == 0 || j == tdk->size + 1)
				ft_putstr_fd("\033[31;1m", STDOUT_FILENO);
			c = tdk->tbl[i][j] + 48;
			ft_putchar_fd(' ', STDOUT_FILENO);
			ft_putchar_fd(c, STDOUT_FILENO);
			if (i == 0 || i == tdk->size + 1 || j == 0 || j == tdk->size + 1)
				ft_putstr_fd("\033[0m", STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}