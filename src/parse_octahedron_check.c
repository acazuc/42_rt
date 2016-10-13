/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_octahedron_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 10:03:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 10:05:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_octahedron_check(t_octahedron *octahedron)
{
	if (octahedron->reflection < 0)
		octahedron->reflection = 0;
	if (octahedron->reflection > 1)
		octahedron->reflection = 1;
	if (octahedron->transparency < 0)
		octahedron->transparency = 0;
	if (octahedron->transparency > 1)
		octahedron->transparency = 1;
	if (octahedron->brilliance < 0)
		octahedron->brilliance = 0;
	if (octahedron->brilliance > 1)
		octahedron->brilliance = 1;
}
