/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pentagon_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:33:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 14:35:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_pentagon_point(t_vector *point, t_parser *p)
{
	point->x = parse_double(p, "Failed to read pentagone point x");
	point->y = parse_double(p, "Failed to read pentagone point y");
	point->z = parse_double(p, "Failed to read pentagone point z");
}
