/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hexagon_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:31:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 16:32:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_hexagon_point(t_vector *vector, t_parser *p)
{
	vector->x = parse_double(p, "Failed to read hexagon point x");
	vector->y = parse_double(p, "Failed to read hexagon point y");
	vector->z = parse_double(p, "Failed to read hexagon point z");
}
