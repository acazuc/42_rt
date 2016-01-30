/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexagon_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:29:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 16:30:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hexagon_free(t_hexagon *hexagon)
{
	free(hexagon->p1);
	free(hexagon->p2);
	free(hexagon->p3);
	free(hexagon->p4);
	free(hexagon->p5);
	free(hexagon->p6);
	free(hexagon);
}
