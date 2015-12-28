/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:00:43 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 16:09:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIGHT_LIST_H
# define FT_LIGHT_LIST_H

# include "light.h"

typedef struct				s_light_list
{
	t_light					*light;
	struct s_light_list		*next;
}							t_light_list;

#endif
