/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:27:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 11:31:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cube		*cube_create(void)
{
	t_cube	*cube;

	if (!(cube = malloc(sizeof(*cube))))
		erorr_quit("Failed to malloc cube");
	cube->p1 = vector_create();
	cube->p2 = vector_create();
	cube->p3 = vector_create();
	cube->p4 = vector_create();
	cube->p5 = vector_create();
	cube->p6 = vector_create();
	cube->reflection = 0;
	cube->transparency = 0;
	cube->brilliance = 0;
	cube->color = WHITE;
	return (cube);
}
