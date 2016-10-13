/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 10:37:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:38:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_camera_position(t_env *env, t_parser *p)
{
	env->position->x = parse_double(p, "Failed to read camera x position");
	env->position->y = parse_double(p, "Failed to read camera y position");
	env->position->z = parse_double(p, "Failed to read camera z position");
}
