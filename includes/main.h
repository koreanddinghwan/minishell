/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:35:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/08 00:26:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include "libft.h"

/*
 * PIPE -> '|', REDIRECTION_OUTPUT -> '>', REDIRECTION_INPUT -> '<'
 * HERE_DOC -> <<, APPENDING_TO -> >>
*/

# define	ECHO	"echo"
# define	CD		"cd"
# define	PWD		"pwd"
# define	EXPORT	"export"
# define	UNSET	"unset"
# define	ENV		"env"
# define	EXIT	"exit"

enum	e_type
{
	COMMAND, BUILTIN, ARG, OPTION, FIL, PIPE, REDIRECTION_OUTPUT, REDIRECTION_INPUT,
	HERE_DOC, APPENDING_TO
};

typedef	struct s_data
{
	char		*command;
	t_dlst		*token_lst;
	t_dlst		*env_lst;
	t_dlst		*cmd_order_lst;
}	t_data;

typedef	struct s_token
{
	enum e_type	type;
	char		*value;
	int			nth;
}	t_token;

typedef	struct s_cmd_order
{
	int		nth;
	t_dlst	*cmd;
}	t_cmd_order;

void	initialize_main(t_data *data, char **envp);
void	set_env_key(t_data *data, char **envp);
/*
 * signal handler
 * */
void	set_handler(void);
void	sigquit_handler(int sig);
void	sigint_handler(int sig);

/*
 * display
 * */
void	display_bash(t_data *data);

/*
 * set_data
 * */
void	initialize_data(t_data *data, char *line);
void	set_token(t_data *data, char *line);
void	set_order(t_data *data);

/*
 * get_type
 *
 * */

int	get_token_type(char *str);
int	check_builtin(char *str);
int	is_special_token(int type);

#endif
