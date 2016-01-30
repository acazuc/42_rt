/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pentagon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:56:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 14:28:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_pentagon		*create_pentagon(void)
{
	t_pentagon		*pentagon;

	if (!(pentagon = malloc(sizeof(*pentagon))))
		error_quit("Failed to malloc pentagon");
	pentagon->p1 = vector_create();
	pentagon->p2 = vector_create();
	pentagon->p3 = vector_create();
	pentagon->p4 = vector_create();
	pentagon->p5 = vector_create();
	pentagon->brilliance = 0;
	pentagon->reflection = 0;
	pentagon->transparency = 0;
	pentagon->color = WHITE;
	return (pentagon);
}
