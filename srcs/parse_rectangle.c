/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 09:58:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:00:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_rectangle(t_rectangle *rectangle, t_parser *p)
{
	p->count = 1;
	while (p->datas[p->count])
	{
		parse_rectangle_part(rectangle, p);
		p->count++;
	}
}
