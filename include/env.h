/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:27:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 11:32:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "object_list.h"
# include "light_list.h"
# include "window.h"
# include "vector.h"

typedef struct		s_env
{
	t_window		*window;
	t_object_list	*objects;
	t_light_list	*lights;
	t_vector		*position;
	t_vector		*rotation;
	double			ambient_light;
	int				max_recur;
	double			fov;
}					t_env;

#endif
