/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:03:40 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 11:25:32 by vheran           ###   ########.fr       */
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
	t_tdk	tdk;

	if (check_args(argc - 1, argv, &tdk) == FAILURE)
		return (FAILURE);
	if (parse_args(argv, &tdk) == FAILURE)
		return (error_msg(0, "MALLOC FAILED\n", FAILURE));
	solver(&tdk, 1);
	print_tbl(&tdk);
	/*if (solver(&tdk, 1) == SUCCESS)
		print_tbl(&tdk);
	else
		ft_putstr_fd("NO CORRECT ANSWER FOUND\n", STDOUT_FILENO);*/
	return (free_tbl(tdk.tbl, tdk.size + 2, SUCCESS));
}