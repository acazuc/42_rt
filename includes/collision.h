/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:18:54 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 15:15:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "object.h"
# include "vector.h"

typedef struct	s_collision
{
	t_object	*object;
	t_vector	*vector;
	t_vector	*normal;
}				t_collision;

#endif
