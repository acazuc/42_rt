/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_collision.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:37:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 13:36:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_COLLISION_H
# define LIGHT_COLLISION_H

# include "collision.h"
# include "light.h"

typedef struct		s_light_collision
{
	t_collision		*collision;
	t_light			*light;
}					t_light_collision;

#endif
