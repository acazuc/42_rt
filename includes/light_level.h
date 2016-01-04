/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_level.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:49:05 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/04 17:23:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_LEVEL_H
# define LIGHT_LEVEL_H

typedef struct		s_light_level
{
	t_ray			*ray;
	t_ray			*origin_ray;
	t_collision		*origin;
	t_color_mask	*mask;
}					t_light_level;

#endif
