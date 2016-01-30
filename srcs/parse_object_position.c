/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:18:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 09:42:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_object_position(t_object *object, t_parser *p)
{
	if (!p->datas[++p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read object x position");
	object->position->x = ft_atod(p->datas[p->count]);
	if (!p->datas[++p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read object y position");
	object->position->y = ft_atod(p->datas[p->count]);
	if (!p->datas[++p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read object z position");
	object->position->z = ft_atod(p->datas[p->count]);
}
