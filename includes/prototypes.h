/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:07:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 16:38:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"
# include "ray.h"
# include "object.h"
# include "vector.h"
# include "point.h"
# include "trinome.h"
# include "light.h"
# include "color_mask.h"
# include "light_collision.h"
# include "parser.h"
# include "collision.h"
# include "light_data.h"

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
t_object		*create_cone(void);
t_object		*create_plane(void);
t_collision		*collide(t_ray *ray, t_object *object);
t_collision		*collide_sphere(t_ray *ray, t_object *sphere);
t_collision		*collide_cylinder(t_ray *ray, t_object *cylinder);
t_collision		*collide_cone(t_ray *ray, t_object *cone);
t_collision		*collide_plane(t_ray *ray, t_object *plane);
void			vector_rotate(t_vector *vector, t_vector *rotation);
void			vector_unrotate(t_vector *vector, t_vector *rotation);
void			vector_rotate_x(t_vector *vector, double angle);
void			vector_rotate_y(t_vector *vector, double angle);
void			vector_rotate_z(t_vector *vector, double angle);
t_light			*light_create(void);
void			light_add(t_env *env, t_light *light);
double			vector_size(t_vector *vector);
void			vector_normalize(t_vector *vector);
double			vector_dot(t_vector *v1, t_vector *v2);
unsigned char	color_get_red(int color);
unsigned char	color_get_green(int color);
unsigned char	color_get_blue(int color);
int				color_create(unsigned char red, unsigned char green
		, unsigned char blue);
t_collision		*collision_create(void);
void			collision_free(t_collision *collision);
int				color_factor(int color, double factor);
t_light_data	*light_level(t_env *env, t_ray *origin_ray
		, t_collision *origin);
void			add_mask(t_color_mask *mask, t_vector *normal_v, t_ray *ray
		, t_light *light);
void			add_mask_specular(t_light_level *ll, t_light *light);
void			add_mask_transparency(t_collision *coll
		, t_light_level *ll, t_light *light);
int				vector_equals(t_vector *v1, t_vector *v2);
t_vector		*vector_multiply(t_vector *vector, double factor);
double			vector_angle(t_vector *v1, t_vector *v2);
t_color_mask	*color_mask_create(void);
void			color_mask_invert(t_color_mask *mask);
int				color_mask(int color, t_color_mask *mask);
t_trinome		*trinome_create(void);
int				get_ray_color(t_env *env, t_ray *ray, t_object *avoid
		, int recur);
t_ray			*get_reflection_ray(t_ray *ray, t_collision *collision);
int				color_add(int c1, int c2);
void			*worker_run(void *data);
t_ray			*get_transparency_ray(t_ray *ray, t_collision *collision);
void			parse_scene(t_env *env, char *file);
void			parse_object(t_object *object, t_parser *parser);
void			parse_light(t_light *light, t_parser *parser);
void			parse_camera(t_env *env, t_parser *parser);
int				parse_color(char *str);
long			epoch_millis();
void			free_objects(t_env *env);
void			free_lights(t_env *env);
t_light_data	*light_data_create(void);
void			light_data_free(t_light_data *data);
void			parse_object_check(t_object *object);
void			parse_light_check(t_light *light);
void			parse_light_position(t_light *light, t_parser *parser);
void			parse_light_mask(t_light *light, t_parser *parser);
int				parse_valid_number(char *data);
void			parse_object_position(t_object *object, t_parser *parser);
void			parse_object_rotation(t_object *object, t_parser *parser);
void			parse_object_dimensions(t_object *object, t_parser *parser);
void			parse_error(t_parser *parser, char *message);

#endif
