/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:32:00 by myukang           #+#    #+#             */
/*   Updated: 2022/06/25 14:21:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "execute.h"
int	get_child_num(t_dlst *cmd_lst)
{
	int	i;

	i = 0;
	while (cmd_lst)
	{	
		i++;
		cmd_lst = cmd_lst->next;
	}
	return (i);
}

void	free_pipes(int **pipes, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

int	**set_pipe(int num)
{
	int	**rtn;
	int	i;

	rtn = malloc(sizeof(int *) * (num - 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (i < num - 1)
	{
		rtn[i] = malloc(sizeof(int) * 2);
		if (!rtn[i])
		{
			free_pipes(rtn, i);
			return (NULL);
		}
		pipe(rtn[i]);
		i++;
	}
	return (rtn);
}
void	exec(t_data *data)
{
	t_dlst	*cmd_lst;
	int		child_num;
	int		**pipe;

	cmd_lst = data->cmd_lst;
	child_num = get_child_num(cmd_lst);
	ft_printf("child num :%d\n", child_num);
	print_cmddata(data);
	if (child_num > 1)
		pipe = set_pipe(child_num);
}
