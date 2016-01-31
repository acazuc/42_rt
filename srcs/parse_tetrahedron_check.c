/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetrahedron_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:35:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 09:53:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_tetrahedron_check(t_tetrahedron *tetrahedron)
{
	if (tetrahedron->reflection < 0)
		tetrahedron->reflection = 0;
	if (tetrahedron->reflection > 1)
		tetrahedron->reflection = 1;
	if (tetrahedron->transparency < 0)
		tetrahedron->transparency = 0;
	if (tetrahedron->transparency > 1)
		tetrahedron->transparency = 1;
	if (tetrahedron->brilliance < 0)
		tetrahedron->brilliance = 0;
	if (tetrahedron->brilliance > 1)
		tetrahedron->brilliance = 1;
}
