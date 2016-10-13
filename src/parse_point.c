/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:09:49 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 09:15:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_point(t_vector *point, t_parser *parser)
{
	point->x = parse_double(parser, "Failed to read point x");
	point->y = parse_double(parser, "Failed to read point y");
	point->z = parse_double(parser, "Failed to read point z");
}
