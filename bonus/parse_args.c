/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:32:56 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 11:28:35 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "towerdoku.h"

int	free_tbl(int **tbl, int i, int ret)
{
	while (--i >= 0)
		free(tbl[i]);
	free(tbl);
	return (ret);
}

void	init_tbl(int **tbl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 6)
	{
		j = -1;
		while (++j < 6)
			tbl[i][j] = 0;
	}
}

void	fill_parameters(int **tbl, char **args, t_tdk *tdk)
{
	int i;
	int j;
	int	last;

	i = 0;
	j = 0;
	last = tdk->size + 1;
	while (++i < last)
		tbl[0][i] = *args[++j] - 48;
	i = 0;
	while (++i < last)
		tbl[last][i] = *args[++j] - 48;
	i = 0;
	while (++i < last)
		tbl[i][0] = *args[++j] - 48;
	i = 0;
	while (++i < last)
		tbl[i][last] = *args[++j] - 48;
}

int	parse_args(char **args, t_tdk *tdk)
{
	int	i;

	tdk->tbl = malloc((tdk->size + 2) *sizeof(int *));
	if (!tdk->tbl)
		return (FAILURE);
	i = -1;
	while (++i < tdk->size + 2)
	{
		tdk->tbl[i] = malloc((tdk->size + 2) * sizeof(int));
		if (!tdk->tbl[i])
		{
			free_tbl(tdk->tbl, i, FAILURE);
			return (FAILURE);
		}
	}
	init_tbl(tdk->tbl);
	fill_parameters(tdk->tbl, args, tdk);
	tdk->line = 1;
	return (SUCCESS);
}