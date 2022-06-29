/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:38:24 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/29 17:38:25 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_env_arr(t_data *data)
{
    char    **envarr;
    int     i;


    envarr = data->env;
    i = 0;
	while (envarr[i])
		free(envarr[i++]);
	free(envarr);
}

char    **dup_env_arr(t_envlst *envlst)
{
    t_envlst *node;
	char	*buffer;
	char	*ex;
	int		i;

    data->env = (char **)malloc(sizeof(char *) * (data->env_size +1));
	i = 0;
	if (!data->env)
		return ;
	while (node)
	{
		buffer = ft_strjoin(node->key, "=");
		ex = buffer;
		buffer = ft_strjoin(buffer, node->value);
		free(ex);
		data->env[i] = buffer;
		node = node->next;
	}
	data->env[i] = 0;
}

void	update_env_arr(t_data *data)
{
	char        **copy;

    copy = dup_env_arr(data->env_lst)
	free_env_arr(data->env);
    data->env = copy;
}