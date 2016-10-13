/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:45:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 09:57:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_camera_part(t_env *env, t_parser *p)
{
	if (!p->datas[p->count])
		parse_error(p, "Failed to read camera's param entry");
	if (!ft_strcmp(p->datas[p->count], "position"))
		parse_camera_position(env, p);
	else if (!ft_strcmp(p->datas[p->count], "rotation"))
		parse_camera_rotation(env, p);
	else if (!ft_strcmp(p->datas[p->count], "fov"))
		env->fov = parse_double(p, "Failed to read fov");
	else
		parse_error(p, "Unknown cameras's param entry");
}

void			parse_camera(t_env *env, t_parser *p)
{
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_camera_part(env, p);
		p->count++;
	}
}
