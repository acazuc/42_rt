/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:43:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 16:36:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_position(t_light *light, t_parser *p)
{
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read light x position");
	light->position->x = ft_atod(p->datas[p->count++]);
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read light y position");
	light->position->y = ft_atod(p->datas[p->count++]);
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read light z position");
	light->position->z = ft_atod(p->datas[p->count]);
}
