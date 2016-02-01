/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:16:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 13:20:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_obj_check(t_obj *obj)
{
	if (obj->reflection < 0)
		obj->reflection = 0;
	if (obj->reflection > 1)
		obj->reflection = 1;
	if (obj->transparency < 0)
		obj->transparency = 0;
	if (obj->transparency > 1)
		obj->transparency = 1;
	if (obj->brilliance < 0)
		obj->brilliance = 0;
	if (obj->brilliance > 1)
		obj->brilliance = 1;
}
