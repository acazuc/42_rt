/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pyramid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:12:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 17:46:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_pyramid_part(t_pyramid *pyramid, t_parser *p)
{
	if (!ft_strcmp(p->datas[p->count], "p1"))
		parse_pyramid_point(pyramid->p1, p);
	else if (!ft_strcmp(p->datas[p->count], "p2"))
		parse_pyramid_point(pyramid->p2, p);
	else if (!ft_strcmp(p->datas[p->count], "p3"))
		parse_pyramid_point(pyramid->p3, p);
	else if (!ft_strcmp(p->datas[p->count], "p4"))
		parse_pyramid_point(pyramid->p4, p);
	else if (!ft_strcmp(p->datas[p->count], "p5"))
		parse_pyramid_point(pyramid->p5, p);
	else if (!ft_strcmp(p->datas[p->count], "reflection"))
		pyramid->reflection = parse_double(p
				, "Failed to read object reflection");
	else if (!ft_strcmp(p->datas[p->count], "transparency"))
		pyramid->transparency = parse_double(p
				, "Failed to read object transparency");
	else if (!ft_strcmp(p->datas[p->count], "brilliance"))
		pyramid->brilliance = parse_double(p
				, "Failed to read object brilliance");
	else if (!ft_strcmp(p->datas[p->count], "color"))
		pyramid->color = parse_color(p);
	else
		parse_error(p, "Unknown objet's param entry");
}

void			parse_pyramid(t_env *env, t_parser *p)
{
	t_pyramid	*pyramid;

	pyramid = create_pyramid();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_pyramid_part(pyramid, p);
		p->count++;
	}
	pyramid_add(env, pyramid);
	parse_pyramid_check(pyramid);
	pyramid_free(pyramid);
}
