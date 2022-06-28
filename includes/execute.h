/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:02:37 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 14:34:55 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "builtin.h"
# include "structs.h"
# include "replacer.h"
# include "fs_bitmasking.h"
# include "getter.h"

void	print_cmddata(t_data *data);
int		set_redir(t_cmd_cont *cmd, t_data *data);
int		make_heredoc(t_data *data);
void	check_execve_error(t_dlst *cmd);
void	close_fd(t_data *data);
int		set_heredocnum(t_dlst *iolst);
void	write_free_strings(t_data *data, char *input, int fd, char *trimmed);
/*
 * execute_sub
 * */
void	execute_builtin(t_data *data, char *cmd, char **args);
void	pipe_first(t_data *data, int i, int *fd[2]);
void	pipe_last(t_data *data, int i, int *fd[2]);
void	pipe_mid(t_data *data, int i, int *fd[2], int pipe_num);
void	execute_dup2(t_data *data, int i, int *fd[2], int pipe_num);

#endif
