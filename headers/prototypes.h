/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:07:45 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 10:12:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

# include "rtv1.h"

void		draw_reset(t_env *env);
void		pixel_put(t_env *env, int x, int y, unsigned int color);
void		error_quit(char *error);
void		draw(t_env *env);
int			trace(t_env *env, t_ray *ray);
void		display(t_env *env);
int			expose_listener(void *param);
void		env_init(t_env *env);
void		window_init(t_env *env);
int			key_listener(int key, void *param);
t_object	*object_create(void);
void		object_add(t_env *env, t_object *object);
t_vector	*vector_create(void);
double		distance_3d(t_vector *v1, t_vector *v2);
t_ray		*ray_create(void);
t_point		*point_create(void);
t_object	*create_sphere(void);
t_object	*create_cylinder(void);
double		collide(t_ray *ray, t_object *object);
double		collide_sphere(t_ray *ray, t_object *sphere);
double		collide_cylinder(t_ray *ray, t_object *cylinder);

#endif
