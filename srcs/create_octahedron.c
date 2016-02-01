/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_octahedron.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:19:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 09:23:56 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_octahedron	*create_octahedron(void)
{
	t_octahedron	*octahedron;

	if (!(octahedron = malloc(sizeof(*octahedron))))
		erorr_quit("Failed to malloc octahedron");
	octahedron->position = vector_create();
	octahedron->rotation = vector_create();
	octahedron->p1 = vector_create();
	octahedron->p2 = vector_create();
	octahedron->p3 = vector_create();
	octahedron->p4 = vector_create();
	octahedron->p5 = vector_create();
	octahedron->p6 = vector_create();
	octahedron->reflection = 0;
	octahedron->transparency = 0;
	octahedron->brilliance = 0;
	octahedron->size = 1;
	octahedron->regular = 0;
	octahedron->color = WHITE;
}
