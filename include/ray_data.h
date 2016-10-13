/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transparency.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:18:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 15:24:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_DATA_H
# define RAY_DATA_H

# include "color_mask.h"
# include "collision.h"
# include "light_data.h"

typedef struct		s_ray_data
{
	int				color;
	t_light_data	*data;
	t_collision		*collision;

}					t_ray_data;

#endif
