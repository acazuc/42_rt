/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:26:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 14:19:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	obj_add(t_env *env, t_obj *obj)
{
	t_obj_file	*file;

	if (!obj->file)
		return ;
	file = obj_parse_file(obj->file);
	(void)env;
	(void)obj;
}
