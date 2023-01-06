/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:32:56 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 11:01:07 by vheran           ###   ########.fr       */
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

void	fill_parameters(int **tbl, char **args)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i < 5)
		tbl[0][i] = *args[++j] - 48;
	i = 0;
	while (++i < 5)
		tbl[5][i] = *args[++j] - 48;
	i = 0;
	while (++i < 5)
		tbl[i][0] = *args[++j] - 48;
	i = 0;
	while (++i < 5)
		tbl[i][5] = *args[++j] - 48;
}

int	**parse_args(char **args)
{
	int	**tbl;
	int	i;

	tbl = malloc(6 *sizeof(int *));
	if (!tbl)
		return (NULL);
	i = -1;
	while (++i < 6)
	{
		tbl[i] = malloc(6 * sizeof(int));
		if (!tbl[i])
		{
			free_tbl(tbl, i, FAILURE);
			return (NULL);
		}
	}
	init_tbl(tbl);
	fill_parameters(tbl, args);
	return (tbl);
}