/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 11:02:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 11:24:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_window(t_env *env, t_parser *p)
{
	if (!p->datas[1] || !parse_valid_number(p->datas[1]))
		parse_error(p, "Invalid window width");
	env->window->width = ft_atoi(p->datas[1]);
	if (!p->datas[2] || !parse_valid_number(p->datas[2]))
		parse_error(p, "Invalid window height");
	env->window->height = ft_atoi(p->datas[2]);
	if (p->datas[3])
		parse_error(p, "Invalid window third parameter");
	if (env->window->width > 2560)
		env->window->width = 2560;
	if (env->window->width < 1)
		env->window->width = 1280;
	if (env->window->height > 1440)
		env->window->height = 1440;
	if (env->window->height < 1)
		env->window->height = 720;
}
