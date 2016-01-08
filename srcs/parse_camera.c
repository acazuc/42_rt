/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:45:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/08 08:29:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_camera_position(t_env *env, char **datas, int count)
{
	if (datas[count])
		env->position->x = ft_atod(datas[count]);
	else
		error_quit("Failed to read camera x position");
	if (datas[count + 1])
		env->position->y = ft_atod(datas[count + 1]);
	else
		error_quit("Failed to read camera y position");
	if (datas[count + 2])
		env->position->z = ft_atod(datas[count + 2]);
	else
		error_quit("Failed to read camera z position");
}

static void		parse_camera_rotation(t_env *env, char **datas, int count)
{
	if (datas[count])
		env->rotation->x = ft_atod(datas[count]);
	else
		error_quit("Failed to read camera x rotation");
	if (datas[count + 1])
		env->rotation->y = ft_atod(datas[count + 1]);
	else
		error_quit("Failed to read camera y rotation");
	if (datas[count + 2])
		env->rotation->z = ft_atod(datas[count + 2]);
	else
		error_quit("Failed to read camera x rotation");
}

static int		parse_camera_part(t_env *env, char **datas, int count)
{
	if (!datas[count])
		error_quit("Failed to read camera's param entry");
	if (!ft_strcmp(datas[count], "position"))
	{
		parse_camera_position(env, datas, count + 1);
		return (3);
	}
	else if (!ft_strcmp(datas[count], "rotation"))
	{
		parse_camera_rotation(env, datas, count + 1);
		return (3);
	}
	error_quit("Unknown cameras's param entry");
	return (0);
}

void			parse_camera(t_env *env, char **datas)
{
	int		count;

	count = 1;
	while (datas[count])
	{
		count += parse_camera_part(env, datas, count);
		count++;
	}
}
