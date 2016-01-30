/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rectangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 10:46:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:48:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rectangle		*create_rectangle(void)
{
	t_rectangle		*rectangle;

	if (!(rectangle = malloc(sizeof(*rectangle))))
		error_quit("Failed to malloc rectangle");
	rectangle->p1 = vector_create();
	rectangle->p2 = vector_create();
	rectangle->p3 = vector_create();
	rectangle->p4 = vector_create();
	rectangle->reflection = 0;
	rectangle->transparency = 0;
	rectangle->brilliance = 0;
	rectangle->color = WHITE;
	return (rectangle);
}
