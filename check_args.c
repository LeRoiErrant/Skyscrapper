/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:12:06 by vheran            #+#    #+#             */
/*   Updated: 2022/06/20 21:32:34 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "towerdoku.h"

static int	is_valid_number(char *argv)
{
	if (argv[1] || argv[0] < 49 || 52 < argv[0])
		return (FAILURE);
	return (SUCCESS);
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 16)
		return (error_msg(0, "INVALID NUMBER OF ARGUMENTS\n", FAILURE));
	i = 0;
	while (argv[++i])
		if (is_valid_number(argv[i]) == FAILURE)
			return (error_msg(argv[i], " ISN'T A VALID NUMBER\n", FAILURE));
	return (SUCCESS);
}