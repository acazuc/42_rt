/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:37:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 13:35:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector.h"
# include "color_mask.h"

typedef struct		s_light
{
	t_vector		*position;
	double			luminosity;
	t_color_mask	*mask;
}					t_light;

#endif
