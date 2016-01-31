/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetrahedron.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 08:55:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 08:58:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_tetrahedron(t_env *env, t_parser *p)
{
	t_tetrahedron	*tetrahedron;

	tetrahedron = create_tetrahedron();
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_tetrahedron_part(tetrahedron, p);
		p->count++;
	}
	parse_tetrahedron_check(tetrahedron);
	tetrahedron_add(env, tetrahedron);
	tetrahedron_free(tetrahedron);
}
