/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:15:57 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 11:21:42 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "towerdoku.h"

void	update_check(int *views, int *max, int new_max)
{
	*views += 1;
	*max = new_max;
}

int	check_view_line(int **tbl, int line, int end)
{
	int	expected;
	int max;
	int i;
	int views;

	expected = tbl[line][0];
	views = 1;
	i = 1;
	max = tbl[line][i];
	while (++i < end)
		if (tbl[line][i] > max)
			update_check(&views, &max, tbl[line][i]);
	if (views != expected)
		return (0);
	expected = tbl[line][end];
	views = 1;
	i = end - 1;
	max = tbl[line][i];
	while (--i > 0)
		if (tbl[line][i] > max)
			update_check(&views, &max, tbl[line][i]);
	if (views != expected)
		return (0);
	return (1);
}

int	check_view_col(int **tbl, int col, int end)
{
	int	expected;
	int max;
	int i;
	int views;

	expected = tbl[0][col];
	views = 1;
	i = 1;
	max = tbl[i][col];
	while (++i < end)
		if (tbl[i][col] > max)
			update_check(&views, &max, tbl[i][col]);
	if (views != expected)
		return (0);
	expected = tbl[end][col];
	views = 1;
	i = end - 1;
	max = tbl[i][col];
	while (--i > 0)
		if (tbl[i][col] > max)
			update_check(&views, &max, tbl[i][col]);
	if (views != expected)
		return (0);
	return (1);
}

int	check_line(int **tbl, int col, int line, int end)
{
	int	i;

	i = col;
	while (--i > 0)
		if (tbl[line][i] == tbl[line][col])
			return (0);
	if (col == end)
		if (!check_view_line(tbl, line, end + 1))
			return (0);
	return (1);
}

int	check_col(int **tbl, int col, int line, int end)
{
	int	i;

	i = line;
	while (--i > 0)
		if (tbl[i][col] == tbl[line][col])
			return (0);
	if (line == end)
		if (!check_view_col(tbl, col, end + 1))
			return(0);
	return (1);
}

int	check_pos(t_tdk *tdk, int col)
{
	if (!check_line(tdk->tbl, col, tdk->line, tdk->size))
		return (0);
	else if (!check_col(tdk->tbl, col, tdk->line, tdk->size))
		return (0);
	return (1);
}

int	solver(t_tdk *tdk, int col)
{
	int i;

	if (col > tdk->size)
	{
		col = 1;
		tdk->line++;
	}
	if (tdk->line == tdk->size + 1)
		return (SUCCESS);
	i = 0;
	while ( ++i < 5)
	{
		tdk->tbl[tdk->line][col] = i;
		if (check_pos(tdk, col))
			if (solver(tdk, col + 1) == SUCCESS)
				return (SUCCESS);
	}
	return (FAILURE);
}