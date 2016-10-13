/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:06:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:25:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	pyramid_free(t_pyramid *pyramid)
{
	free(pyramid->position);
	free(pyramid->rotation);
	free(pyramid->p1);
	free(pyramid->p2);
	free(pyramid->p3);
	free(pyramid->p4);
	free(pyramid->p5);
	free(pyramid);
}
