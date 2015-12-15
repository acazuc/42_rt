/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:27:19 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/15 11:35:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

# include "window.h"
# include "object_list.h"
# include "light_list.h"
# include "vector.h"

typedef struct		s_env
{
	t_window		*window;
	t_object_list	*objects;
	t_light_list	*lights;
	t_vector		*position;
	int				fov;
	double angle;
}					t_env;

#endif
