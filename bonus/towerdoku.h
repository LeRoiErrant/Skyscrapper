/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   towerdoku.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:07:06 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 11:20:47 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOWERDOKU_H
# define TOWERDOKU_H

# define FAILURE 1
# define SUCCESS 0

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef	struct s_tdk
{
	int	size;
	int	**tbl;
	int	line;
}		t_tdk;

int		error_msg(char *arg, char *msg, int errnum);
int		check_args(int argc, char **argv, t_tdk *tdk);
int		parse_args(char **args, t_tdk *tdk);
int		free_tbl(int **tbl, int i, int ret);
int		solver(t_tdk *tdk, int col);
void	print_tbl(t_tdk *tdk);
int		ft_putstr_fd(char *str, int fd);


#endif