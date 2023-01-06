/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   towerdoku.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:07:06 by vheran            #+#    #+#             */
/*   Updated: 2022/06/21 00:19:13 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOWERDOKU_H
# define TOWERDOKU_H

# define FAILURE 1
# define SUCCESS 0

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		error_msg(char *arg, char *msg, int errnum);
int		check_args(int argc, char **argv);
int		**parse_args(char **args);
int		free_tbl(int **tbl, int i, int ret);
int		solver(int **tbl, int col, int line);
void	print_tbl(int **tbl);
int		ft_putstr_fd(char *str, int fd);


#endif