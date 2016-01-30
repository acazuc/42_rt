/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 10:27:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:53:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_rectangle_point(t_vector *point, t_parser *p)
{
	point->x = parse_double(p, "Failed to read rectangle point x");
	point->y = parse_double(p, "Failed to read rectangle point y");
	point->z = parse_double(p, "Failed to read rectangle point z");
}
