/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:24 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/29 12:31:27 by gyumpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_env(t_data *data)
{
	t_envlst	*lst;

	lst = data->env_lst;
	while (lst)
	{
		printf("%s=%s\n", (char *)lst->key, (char *)lst->value);
		lst = lst->next;
	}
}
