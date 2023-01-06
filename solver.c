/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:15:57 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 11:16:11 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "towerdoku.h"

void	update_check(int *views, int *max, int new_max)
{
	*views += 1;
	*max = new_max;
}

int	check_view_line(int **tbl, int line)
{
	int	expected;
	int max;
	int i;
	int views;

	expected = tbl[line][0];
	views = 1;
	i = 1;
	max = tbl[line][i];
	while (++i < 5)
		if (tbl[line][i] > max)
			update_check(&views, &max, tbl[line][i]);
	if (views != expected)
		return (0);
	expected = tbl[line][5];
	views = 1;
	i = 4;
	max = tbl[line][i];
	while (--i > 0)
		if (tbl[line][i] > max)
			update_check(&views, &max, tbl[line][i]);
	if (views != expected)
		return (0);
	return (1);
}

int	check_view_col(int **tbl, int col)
{
	int	expected;
	int max;
	int i;
	int views;

	expected = tbl[0][col];
	views = 1;
	i = 1;
	max = tbl[i][col];
	while (++i < 5)
		if (tbl[i][col] > max)
			update_check(&views, &max, tbl[i][col]);
	if (views != expected)
		return (0);
	expected = tbl[5][col];
	views = 1;
	i = 4;
	max = tbl[i][col];
	while (--i > 0)
		if (tbl[i][col] > max)
			update_check(&views, &max, tbl[i][col]);
	if (views != expected)
		return (0);
	return (1);
}

int	check_line(int **tbl, int col, int line)
{
	int	i;

	i = col;
	while (--i > 0)
		if (tbl[line][i] == tbl[line][col])
			return (0);
	if (col == 4)
		if (!check_view_line(tbl, line))
			return (0);
	return (1);
}

int	check_col(int **tbl, int col, int line)
{
	int	i;

	i = line;
	while (--i > 0)
		if (tbl[i][col] == tbl[line][col])
			return (0);
	if (line == 4)
		if (!check_view_col(tbl, col))
			return(0);
	return (1);
}

int	check_pos(int **tbl, int col, int line)
{
	if (!check_line(tbl, col, line))
		return (0);
	else if (!check_col(tbl, col, line))
		return (0);
	return (1);
}

int	solver(int **tbl, int col, int line)
{
	int i;

	if (col > 4)
	{
		col = 1;
		line++;
	}
	if (line == 5)
		return (SUCCESS);
	i = 0;
	while ( ++i < 5)
	{
		tbl[line][col] = i;
		if (check_pos(tbl, col, line))
			if (solver(tbl, col + 1, line) == SUCCESS)
				return (SUCCESS);
	}
	return (FAILURE);
}