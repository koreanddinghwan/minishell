/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:44:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 14:45:55 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include <string.h>
# include "structs.h"
# include "libft.h"
# include "lexer.h"

void	ft_env(t_data *data);
void	ft_cd(t_data *data, char **path);
void	ft_pwd(void);
void	ft_export(t_data *data, char **args);
void	ft_unset(t_data *data, char **args);
void	ft_echo(t_data *data, char **argv);
void	ft_exit(int ac, char *av[]);
int		ft_isunder(int c);

#endif
