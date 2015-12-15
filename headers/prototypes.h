/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:07:45 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/15 09:30:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

# include "env.h"
# include "ray.h"
# include "object.h"
# include "vector.h"
# include "point.h"
# include "light.h"
# include "collision.h"

void			draw_reset(t_env *env);
void			pixel_put(t_env *env, int x, int y, unsigned int color);
void			error_quit(char *error);
void			draw(t_env *env);
t_collision		*trace(t_env *env, t_ray *ray, t_object *avoid);
void			display(t_env *env);
int				expose_listener(void *param);
void			env_init(t_env *env);
void			window_init(t_env *env);
int				key_listener(int key, void *param);
t_object		*object_create(void);
void			object_add(t_env *env, t_object *object);
t_vector		*vector_create(void);
double			distance_3d(t_vector *v1, t_vector *v2);
t_ray			*ray_create(void);
void			ray_free(t_ray *ray);
t_point			*point_create(void);
t_object		*create_sphere(void);
t_object		*create_cylinder(void);
t_vector		*collide(t_ray *ray, t_object *object);
t_vector		*collide_sphere(t_ray *ray, t_object *sphere);
t_vector		*collide_cylinder(t_ray *ray, t_object *cylinder);
void			vector_rotate(t_vector *vector, t_vector *rotation);
void			vector_unrotate(t_vector *vector, t_vector *rotation);
void			vector_rotate_x(t_vector *vector, double angle);
void			vector_rotate_y(t_vector *vector, double angle);
void			vector_rotate_z(t_vector *vector, double angle);
t_light			*light_create(void);
void			light_add(t_env *env, t_light *light);
double			vector_size(t_vector *vector);
void			vector_normalize(t_vector *vector);
unsigned char	color_get_red(int color);
unsigned char	color_get_green(int color);
unsigned char	color_get_blue(int color);
t_collision		*collision_create(void);
int				color_factor(int color, double factor);
double			light_level(t_env *env, t_collision *origin);
int				vector_equals(t_vector *v1, t_vector *v2);
t_vector		*vector_multiply(t_vector *vector, double factor);
double			vector_angle(t_vector *v1, t_vector *v2);
t_vector		*normal_sphere(t_object *sphere, t_vector *point);

#endif
