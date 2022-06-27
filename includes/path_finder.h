/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:46:46 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 01:23:51 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_FINDER_H
# define PATH_FINDER_H
# include "structs.h"
# include "fs_bitmasking.h"
# include <sys/stat.h>

char	*cmdpath_finder(t_envlst *envlst, char *cmd);
char	*iopath_finder(char *path, int type);
char	*check_envpath(char *path, char *cmd);
#endif
