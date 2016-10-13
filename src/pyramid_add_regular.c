/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_add_regular.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:32:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:39:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	pyramid_add_regular(t_pyramid *pyramid)
{
	pyramid->p1->x = -1 * pyramid->size / 2.;
	pyramid->p1->y = -1 * pyramid->size / 2.;
	pyramid->p1->z = 1 * pyramid->size / 2.;
	pyramid->p2->x = 1 * pyramid->size / 2.;
	pyramid->p2->y = -1 * pyramid->size / 2.;
	pyramid->p2->z = 1 * pyramid->size / 2.;
	pyramid->p3->x = 1 * pyramid->size / 2.;
	pyramid->p3->y = -1 * pyramid->size / 2.;
	pyramid->p3->z = -1 * pyramid->size / 2.;
	pyramid->p4->x = -1 * pyramid->size / 2.;
	pyramid->p4->y = -1 * pyramid->size / 2.;
	pyramid->p4->z = -1 * pyramid->size / 2.;
	pyramid->p5->x = 0;
	pyramid->p5->y = 1 * pyramid->size / 2.;
	pyramid->p5->z = 0;
}
