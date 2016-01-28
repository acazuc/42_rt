/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:45:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 16:11:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_camera_position(t_env *env, t_parser *p)
{
	if (!p->datas[p->count]
			|| !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read camera x position");
	env->position->x = ft_atod(p->datas[p->count]);
	if (!p->datas[p->count + 1]
			|| !parse_valid_number(p->datas[p->count + 1]))
		parse_error(p, "Failed to read camera y position");
	env->position->y = ft_atod(p->datas[p->count + 1]);
	if (!p->datas[p->count + 2]
			|| !parse_valid_number(p->datas[p->count + 2]))
		parse_error(p, "Failed to read camera z position");
	env->position->z = ft_atod(p->datas[p->count + 2]);
}

static void		parse_camera_rotation(t_env *env, t_parser *p)
{
	if (p->datas[p->count])
		env->rotation->x = ft_atod(p->datas[p->count]);
	else
		parse_error(p, "Failed to read camera x rotation");
	if (p->datas[p->count + 1])
		env->rotation->y = ft_atod(p->datas[p->count + 1]);
	else
		parse_error(p, "Failed to read camera y rotation");
	if (p->datas[p->count + 2])
		env->rotation->z = ft_atod(p->datas[p->count + 2]);
	else
		parse_error(p, "Failed to read camera x rotation");
}

static int		parse_camera_part(t_env *env, t_parser *p)
{
	if (!p->datas[p->count])
		parse_error(p, "Failed to read camera's param entry");
	if (!ft_strcmp(p->datas[p->count], "position"))
	{
		p->count++;
		parse_camera_position(env, p);
		p->count--;
		return (3);
	}
	else if (!ft_strcmp(p->datas[p->count], "rotation"))
	{
		p->count++;
		parse_camera_rotation(env, p);
		p->count--;
		return (3);
	}
	parse_error(p, "Unknown cameras's param entry");
	return (0);
}

void			parse_camera(t_env *env, t_parser *p)
{
	p->count = 1;
	while (p->datas[p->count])
	{
		p->count += parse_camera_part(env, p);
		p->count++;
	}
}
