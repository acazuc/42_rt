/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octahedron_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 10:07:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 10:08:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			octahedron_add(t_env *env, t_octahedron *octahedron)
{
	if (octahedron->regular)
	{
		octahedron_add_regular(octahedron);
		octahedron_add_rotate(octahedron);
		octahedron_add_moves(octahedron);
	}
	octahedron_add_points(env, octahedron);
}
