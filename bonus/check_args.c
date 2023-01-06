/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:12:06 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 11:24:32 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "towerdoku.h"

static int	check_argc(int argc)
{
	if (argc == 4 * 4)
		return (4);
	else if (argc == 4 * 5)
		return (5);
	else if (argc == 4 * 6)
		return (6);
	else if (argc == 4 * 7)
		return (7);
	else if (argc == 4 * 8)
		return (8);
	else if (argc == 4 * 9)
		return (9);
	else
		return (0);	
}

static int	is_valid_number(char *argv, t_tdk *tdk)
{
	if (argv[1] || argv[0] < 49 || (tdk->size + 48) < argv[0])
		return (FAILURE);
	return (SUCCESS);
}

int	check_args(int argc, char **argv, t_tdk *tdk)
{
	int	i;

	tdk->size = check_argc(argc);
	if (!tdk->size)
		return (error_msg(0, "INVALID NUMBER OF ARGUMENTS\n", FAILURE));
	i = 0;
	while (argv[++i])
		if (is_valid_number(argv[i], tdk) == FAILURE)
			return (error_msg(argv[i], " ISN'T A VALID NUMBER\n", FAILURE));
	return (SUCCESS);
}