/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transparency.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:18:06 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/20 10:31:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAY_DATA_H
# define FT_RAY_DATA_H

# include "color_mask.h"
# include "collision.h"

typedef struct		s_ray_data
{
	int				color;
	t_color_mask	*mask;
	t_collision		*collision;

}					t_ray_data;

#endif
