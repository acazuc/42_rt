/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pyramid_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:20:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 17:21:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_pyramid_point(t_vector *point, t_parser *p)
{
	point->x = parse_double(p, "Failed to read pyramid point x");
	point->y = parse_double(p, "Failed to read pyramid point y");
	point->z = parse_double(p, "Failed to read pyramid point z");
}
