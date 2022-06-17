/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:36:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 23:45:27 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "structs.h"
# include "defines_enums.h"
# include <stdio.h>
void		ft_cd(t_data *data, char *path);
void		ft_echo(t_data *data, int flag, char *str);
void		ft_exit(int ac, char *av[]);
void		ft_export(t_data *data, char **args);
void		ft_pwd(void);
void		ft_unset(t_data *data, char **args);
t_envlst	*ft_envlst_new(void *c);
void		ft_envlst_pushback(t_envlst **envlst, t_envlst *new);
t_envlst	*ft_envlst_last(t_envlst *envlst);
#endif
