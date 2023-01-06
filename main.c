/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:03:40 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 00:20:02 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "towerdoku.h"

int	ft_strlen(char *str)
{
	int l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

int	error_msg(char *arg, char *msg, int errnum)
{
	write(STDERR_FILENO, "ERROR", 5);
	if (arg || msg)
		write(STDERR_FILENO, ": ", 2);
	if (arg)
	{
		write(STDERR_FILENO, "\"", 1);
		write(STDERR_FILENO, arg, ft_strlen(arg));
		write(STDERR_FILENO, "\"", 1);
	}
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	return (errnum);
}

int	main(int argc, char **argv)
{
	int	**tbl;

	if (check_args(argc - 1, argv) == FAILURE)
		return (FAILURE);
	tbl = parse_args(argv);
	if (!tbl)
		return (error_msg(0, "MALLOC FAILED\n", FAILURE));
	if (solver(tbl, 1, 1) == SUCCESS)
		print_tbl(tbl);
	else
		ft_putstr_fd("NO CORRECT ANSWER FOUND\n", STDOUT_FILENO);
	free_tbl(tbl, 6, SUCCESS);
	return (SUCCESS);
}