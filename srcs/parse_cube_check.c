/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:43:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 12:45:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_cube_check(t_cube *cube)
{
	if (cube->reflection < 0)
		cube->reflection =  0;
	if (cube->reflection > 1)
		cube->reflection = 1;
	if (cube->transparency < 0)
		cube->transparency = 0;
	if (cube->transparency > 1)
		cube->transparency = 1;
	if (cube->brilliance < 0)
		cube->brilliance = 0;
	if (cube->brilliance > 1)
		cube->brilliance = 1;
}
