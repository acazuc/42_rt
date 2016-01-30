/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:32:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 12:33:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_cube_point(t_vector *point, t_parser *p)
{
	point->x = parse_double(p, "Failed to read object point x");
	point->y = parse_double(p, "Failed to read object point y");
	point->z = parse_double(p, "Failed to read object point z");
}
