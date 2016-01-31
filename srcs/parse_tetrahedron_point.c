/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetrahedron_point.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:07:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 09:09:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_tetrahedron_point(t_vector *point, t_parser* p)
{
	point->x = parse_double(p, "Failed to read tetrahedron point x");
	point->y = parse_double(p, "Failed to read tetrahedron point y");
	point->z = parse_double(p, "Failed to read tetrahedron point z");
}
