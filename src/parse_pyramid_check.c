/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pyramid_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:21:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 17:23:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_pyramid_check(t_pyramid *pyramid)
{
	if (pyramid->reflection < 0)
		pyramid->reflection = 0;
	if (pyramid->reflection > 1)
		pyramid->reflection = 1;
	if (pyramid->transparency < 0)
		pyramid->transparency = 0;
	if (pyramid->transparency > 1)
		pyramid->transparency = 1;
	if (pyramid->brilliance < 0)
		pyramid->brilliance = 0;
	if (pyramid->brilliance > 1)
		pyramid->brilliance = 1;
}
