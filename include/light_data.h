/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:17:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 15:57:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_DATA_H
# define LIGHT_DATA_H

# include "color_mask.h"

typedef struct	s_light_data
{
	t_color_mask	*mask;
	t_color_mask	*spec;
}				t_light_data;

#endif
