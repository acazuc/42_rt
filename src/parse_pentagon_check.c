/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pentagon_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:36:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 14:38:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_pentagon_check(t_pentagon *pentagon)
{
	if (pentagon->reflection < 0)
		pentagon->reflection = 0;
	if (pentagon->reflection > 1)
		pentagon->reflection = 1;
	if (pentagon->transparency < 0)
		pentagon->transparency = 0;
	if (pentagon->transparency > 1)
		pentagon->transparency = 1;
	if (pentagon->brilliance < 0)
		pentagon->brilliance = 0;
	if (pentagon->brilliance > 1)
		pentagon->brilliance = 1;
}
