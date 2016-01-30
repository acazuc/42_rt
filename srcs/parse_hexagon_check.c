/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hexagon_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:33:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 16:43:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_hexagon_check(t_hexagon *hexagon)
{
	if (hexagon->reflection < 0)
		hexagon->reflection = 0;
	if (hexagon->reflection > 1)
		hexagon->reflection = 1;
	if (hexagon->transparency < 0)
		hexagon->transparency = 0;
	if (hexagon->transparency > 1)
		hexagon->transparency = 1;
	if (hexagon->brilliance < 0)
		hexagon->brilliance = 0;
	if (hexagon->brilliance > 1)
		hexagon->brilliance = 1;
}
