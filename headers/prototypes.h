/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:07:45 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 14:15:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

# include "rtv1.h"

void		draw_reset(t_env *env);
void		pixel_put(t_env *env, int x, int y, unsigned int color);
void		error_quit(char *error);
void		draw(t_env *env);
int			trace(t_env *env, double angle_x, double angle_y);
void		display(t_env *env);
int			expose_listener(void *param);
void		env_init(t_env *env);
void		window_init(t_env *env);
int			key_listener(int key, void *param);
t_object	*object_create(void);
void		object_add(t_env *env, t_object *object);
t_vector	*vector_create(void);
double		distance_3d(t_vector *v1, t_vector *v2);
t_point		*point_create(void);
t_object	*create_sphere(void);
double		collide(t_vector *vector, t_object *object);
double		collide_sphere(t_vector *vector, t_object *object);

#endif
