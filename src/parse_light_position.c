/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:43:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:35:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_light_position(t_light *light, t_parser *p)
{
	light->position->x = parse_double(p, "Failed to read light x position");
	light->position->y = parse_double(p, "Failed to read light y position");
	light->position->z = parse_double(p, "Failed to read light z position");
}
