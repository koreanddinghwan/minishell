/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:02:37 by myukang           #+#    #+#             */
/*   Updated: 2022/06/27 03:53:28 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include "builtin.h"
# include "structs.h"
# include <fcntl.h>
# include "replacer.h"
void	print_cmddata(t_data *data);
int	set_redir(t_cmd_cont *cmd, t_data *data);
int	set_heredoc(t_cmd_cont *cmd, t_data *data);
#endif
