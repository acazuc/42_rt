/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:03:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 13:07:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_ambient_light(t_env *env, t_parser *p)
{
	if (!p->datas[1] || !parse_valid_number(p->datas[1]))
		parse_error(p, "Invalid ambient light value");
	env->ambient_light = ft_atod(p->datas[1]);
	if (p->datas[2])
		parse_error(p, "Invalid ambient light second parameter");
	if (env->ambient_light < 0)
		env->ambient_light = 0;
	if (env->ambient_light > 1)
		env->ambient_light = 1;
}
