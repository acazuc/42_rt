/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:46:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 16:25:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_mask(t_light *light, t_parser *p)
{
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read light red mask");
	light->mask->red = ft_atod(p->datas[p->count++]);
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read light green mask");
	light->mask->green = ft_atod(p->datas[p->count++]);
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read light blue mask");
	light->mask->blue = ft_atod(p->datas[p->count]);
}
