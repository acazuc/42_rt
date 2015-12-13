/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:27:19 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 16:02:41 by acazuc           ###   ########.fr       */
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
}					t_env;

#endif
