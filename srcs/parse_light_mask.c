/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:46:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:36:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_mask(t_light *light, t_parser *p)
{
	light->mask->red = parse_double(p, "Failed to read light red mask");
	light->mask->green = parse_double(p, "Failed to read light green mask");
	light->mask->blue = parse_double(p, "Failed to read light blue mask");
}
