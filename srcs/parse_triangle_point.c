/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:30:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 14:44:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_triangle_point(double *x, double *y, double *z, t_parser *p)
{
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read triangle point x");
	*x = ft_atod(p->datas[p->count++]);
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read triangle point y");
	*y = ft_atod(p->datas[p->count++]);
	if (!p->datas[p->count] || !parse_valid_number(p->datas[p->count]))
		parse_error(p, "Failed to read triangle point z");
	*z = ft_atod(p->datas[p->count]);
}
