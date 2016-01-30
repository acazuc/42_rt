/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 10:37:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:39:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_camera_rotation(t_env *env, t_parser *p)
{
	env->rotation->x = parse_double(p, "Failed to read camera x rotation");
	env->rotation->y = parse_double(p, "Failed to read camera y rotation");
	env->rotation->z = parse_double(p, "Failed to read camera z rotation");
}
