/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:18:54 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/14 11:30:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLLISION_H
# define FT_COLLISION_H

# include "object.h"
# include "vector.h"

typedef struct	s_collision
{
	t_object	*object;
	t_vector	*vector;
}				t_collision;

#endif
