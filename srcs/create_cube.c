/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:34:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 12:40:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cube	*create_cube(void)
{
	t_cube	*cube;

	if (!(cube = malloc(sizeof(*cube))))
		error_quit("Failed to malloc cube");
	cube->p1 = vector_create();
	cube->p2 = vector_create();
	cube->p3 = vector_create();
	cube->p4 = vector_create();
	cube->p5 = vector_create();
	cube->p6 = vector_create();
	cube->p7 = vector_create();
	cube->p8 = vector_create();
	cube->reflection = 0;
	cube->transparency = 0;
	cube->brilliance = 0;
	cube->color = WHITE;
	return (cube);
}
