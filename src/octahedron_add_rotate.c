/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octahedron_add_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:07:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 11:08:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	octahedron_add_rotate(t_octahedron *octahedron)
{
	vector_rotate(octahedron->p1, octahedron->rotation);
	vector_rotate(octahedron->p2, octahedron->rotation);
	vector_rotate(octahedron->p3, octahedron->rotation);
	vector_rotate(octahedron->p4, octahedron->rotation);
	vector_rotate(octahedron->p5, octahedron->rotation);
	vector_rotate(octahedron->p6, octahedron->rotation);
}
