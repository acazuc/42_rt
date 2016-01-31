/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_add_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:31:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:32:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	pyramid_add_moves(t_pyramid *pyramid)
{
	pyramid->p1->x += pyramid->position->x;
	pyramid->p1->y += pyramid->position->y;
	pyramid->p1->z += pyramid->position->z;
	pyramid->p2->x += pyramid->position->x;
	pyramid->p2->y += pyramid->position->y;
	pyramid->p2->z += pyramid->position->z;
	pyramid->p3->x += pyramid->position->x;
	pyramid->p3->y += pyramid->position->y;
	pyramid->p3->z += pyramid->position->z;
	pyramid->p4->x += pyramid->position->x;
	pyramid->p4->y += pyramid->position->y;
	pyramid->p4->z += pyramid->position->z;
	pyramid->p5->x += pyramid->position->x;
	pyramid->p5->y += pyramid->position->y;
	pyramid->p5->z += pyramid->position->z;
}
