/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:30:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:30:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_triangle_point(double *x, double *y, double *z, t_parser *p)
{
	*x = parse_double(p, "Failed to read triangle point x");
	*y = parse_double(p, "Failed to read triangle point y");
	*z = parse_double(p, "Failed to read triangle point z");
}
