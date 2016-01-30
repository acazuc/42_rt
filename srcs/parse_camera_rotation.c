/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 10:37:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 09:57:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_camera_rotation(t_env *env, t_parser *p)
{
	if (!p->datas[++p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read camera x rotation");
	env->rotation->x = ft_atod(p->datas[p->count]);
	if (!p->datas[++p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read camera y rotation");
	env->rotation->y = ft_atod(p->datas[p->count]);
	if (!p->datas[++p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read camera z rotation");
	env->rotation->z = ft_atod(p->datas[p->count]);
}
