/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:38:24 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/29 19:18:25 by myukang          ###   ########.fr       */
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

void	free_env_lst(t_envlst *lst)
{
	t_envlst	*next;

	while (lst)
	{
		next = lst->next;
		free(lst->key);
		free(lst->value);
		free(lst);
		lst = next;
	}
}
void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	ft_isunder(int c)
{
	if (c == '_')
		return (1);
	return (0);
}
char    **dup_env_arr(t_envlst *envlst)
{
	char	*buffer;
	char	*ex;
	int		i;
	char	**copy;

    copy = (char **)malloc(sizeof(char *) * (ft_envlst_size(envlst) +1));
	i = 0;
	if (!copy)
		return (NULL);
	while (envlst)
	{
		buffer = ft_strjoin(envlst->key, "=");
		ex = buffer;
		buffer = ft_strjoin(buffer, envlst->value);
		free(ex);
		copy[i] = buffer;
		envlst = envlst->next;
		i++;
	}
	copy[i] = 0;
	return (copy);
}

void	update_env_arr(t_data *data)
{
	char        **copy;

    copy = dup_env_arr(data->env_lst);
	free_env_arr(data);
    data->env = copy;
}
