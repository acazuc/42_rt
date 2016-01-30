/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pentagone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:56:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 13:58:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_pentagone		*create_pentagone(void)
{
	t_pentagone		*pentagone;

	if (!(pentagone = malloc(sizeof(*pentagone))))
		error_quit("Failed to malloc pentagone");
	pentagone->p1 = vector_create();
	pentagone->p2 = vector_create();
	pentagone->p3 = vector_create();
	pentagone->p4 = vector_create();
	pentagone->p5 = vector_create();
	pentagone->brilliance = 0;
	pentagone->reflection = 0;
	pentagone->transparency = 0;
	pentagone->color = WHITE;
	return (pentagone);
}
