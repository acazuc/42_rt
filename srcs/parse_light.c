/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:49:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 16:38:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_light_part(t_light *light, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "position"))
	{
		p->count++;
		parse_light_position(light, p);
	}
	else if (!ft_strcmp(p->datas[p->count], "color"))
	{
		p->count++;
		parse_light_mask(light, p);
	}
	else if (!ft_strcmp(p->datas[p->count], "luminosity"))
	{
		p->count++;
		if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
			parse_error(p, "Failed to parse light luminosity");
		light->luminosity = ft_atod(p->datas[p->count]);
	}
	else
		parse_error(p, "Unknown light's param entry");
}

void			parse_light(t_light *light, t_parser *p)
{
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_light_part(light, p);
		p->count++;
	}
	parse_light_check(light);
}
