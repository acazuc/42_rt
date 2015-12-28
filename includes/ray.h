/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 09:42:33 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/18 16:33:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAY_H
# define FT_RAY_H

# include "vector.h"

typedef struct		s_ray
{
	t_vector		*direction;
	t_vector		*origin;
}					t_ray;

#endif
