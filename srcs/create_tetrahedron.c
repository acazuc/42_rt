/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetrahedron.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:03:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 11:46:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_tetrahedron	*create_tetrahedron(void)
{
	t_tetrahedron	*tetrahedron;

	if (!(tetrahedron = malloc(sizeof(*tetrahedron))))
		error_quit("Failed to malloc tetrahedron");
	tetrahedron->position = vector_create();
	tetrahedron->rotation = vector_create();
	tetrahedron->p1 = vector_create();
	tetrahedron->p2 = vector_create();
	tetrahedron->p3 = vector_create();
	tetrahedron->p4 = vector_create();
	tetrahedron->reflection = 0;
	tetrahedron->transparency = 0;
	tetrahedron->brilliance = 0;
	tetrahedron->size = 0;
	tetrahedron->regular = 0;
	tetrahedron->color = WHITE;
	return (tetrahedron);
}
