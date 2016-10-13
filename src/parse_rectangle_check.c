/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:41:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 12:45:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_rectangle_check(t_rectangle *rectangle)
{
	if (rectangle->reflection < 0)
		rectangle->reflection = 0;
	if (rectangle->reflection > 1)
		rectangle->reflection = 1;
	if (rectangle->transparency < 0)
		rectangle->transparency = 0;
	if (rectangle->transparency > 1)
		rectangle->transparency = 1;
	if (rectangle->brilliance < 0)
		rectangle->brilliance = 0;
	if (rectangle->brilliance > 1)
		rectangle->brilliance = 1;
}
