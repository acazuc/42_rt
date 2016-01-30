/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pyramid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:01:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 17:05:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_pyramid	*create_pyramid(void)
{
	t_pyramid	*pyramid;

	if (!(pyramid = malloc(sizeof(*pyramid))))
		error_quit("Failed to mallco pyramid");
	pyramid->p1 = vector_create();
	pyramid->p2 = vector_create();
	pyramid->p3 = vector_create();
	pyramid->p4 = vector_create();
	pyramid->p5 = vector_create();
	pyramid->reflection = 0;
	pyramid->transparency = 0;
	pyramid->brilliance = 0;
	pyramid->color = WHITE;
	return (pyramid);
}
