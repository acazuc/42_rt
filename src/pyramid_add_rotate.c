/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_add_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:30:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:31:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	pyramid_add_rotate(t_pyramid *pyramid)
{
	vector_rotate(pyramid->p1, pyramid->rotation);
	vector_rotate(pyramid->p2, pyramid->rotation);
	vector_rotate(pyramid->p3, pyramid->rotation);
	vector_rotate(pyramid->p4, pyramid->rotation);
	vector_rotate(pyramid->p5, pyramid->rotation);
}
