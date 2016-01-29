/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 10:37:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 10:43:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_camera_position(t_env *env, t_parser *p)
{
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read camera x position");
	env->position->x = ft_atod(p->datas[p->count++]);
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read camera y position");
	env->position->y = ft_atod(p->datas[p->count++]);
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read camera z position");
	env->position->z = ft_atod(p->datas[p->count]);
}
