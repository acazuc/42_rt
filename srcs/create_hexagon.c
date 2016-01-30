/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hexagon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:37:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 15:41:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hexagon	*create_hexagon(void)
{
	t_hexagon	*hexagon;

	if (!(hexagon = malloc(sizeof(*hexagon))))
		error_quit("Failed to malloc hexagon");
	hexagon->p1 = vector_create();
	hexagon->p2 = vector_create();
	hexagon->p3 = vector_create();
	hexagon->p4 = vector_create();
	hexagon->p5 = vector_create();
	hexagon->p6 = vector_create();
	hexagon->reflection = 0;
	hexagon->transparency = 0;
	hexagon->brilliance = 0;
	hexagon->color = WHITE;
	return (hexagon);
}
