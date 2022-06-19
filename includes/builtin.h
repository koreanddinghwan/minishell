#ifndef BUILTIN_H
# define BUILTIN_H

#include "structs.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

#include "lexer.h"

/*
 * env
 * */
void    ft_env(t_data   *data);

/*
 * cd
 * */
void	ft_cd(t_data *data, char *path);

/*
 * pwd
 * */
void	ft_pwd();

/*
 * export
 * */
void	ft_export(t_data *data, char **args);

/*
 * unset
 * */
void	ft_unset(t_data *data, char **args);

/*
 * echo
 * */
void	ft_echo(t_data *data, int flag, char *str);

/*
 * exit
 * */
void	ft_exit(int ac, char *av[]);

#endif
