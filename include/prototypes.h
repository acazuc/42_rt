/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:07:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 16:08:29 by acazuc           ###   ########.fr       */
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
# include "rectangle.h"
# include "cube.h"
# include "pentagon.h"
# include "hexagon.h"
# include "pyramid.h"
# include "tetrahedron.h"
# include "octahedron.h"
# include "obj.h"
# include "obj_file.h"

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
t_object		*create_triangle(void);
t_rectangle		*create_rectangle(void);
t_cube			*create_cube(void);
t_pentagon		*create_pentagon(void);
t_hexagon		*create_hexagon(void);
t_pyramid		*create_pyramid(void);
t_tetrahedron	*create_tetrahedron(void);
t_octahedron	*create_octahedron(void);
t_obj			*create_obj(void);
t_collision		*collide(t_ray *ray, t_object *object);
t_collision		*collide_sphere(t_ray *ray, t_object *sphere);
t_collision		*collide_cylinder(t_ray *ray, t_object *cylinder);
t_collision		*collide_cone(t_ray *ray, t_object *cone);
t_collision		*collide_plane(t_ray *ray, t_object *plane);
t_collision		*collide_triangle(t_ray *ray, t_object *object);
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
void			vector_dup(t_vector *v1, t_vector *v2);
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
void			parse_camera_position(t_env *env, t_parser *p);
void			parse_camera_rotation(t_env *env, t_parser *p);
int				parse_color(t_parser *parser);
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
void			parse_window(t_env *env, t_parser *parser);
void			parse_error(t_parser *parser, char *message);
void			parse_ambient_light(t_env *env, t_parser *p);
void			parse_triangle(t_env *env, t_parser *parser);
void			parse_triangle_point(double *x, double *y, double *z
		, t_parser *parser);
double			parse_double(t_parser *parser, char *error);
void			parse_point(t_vector *point, t_parser *parser);
void			parse_reflection(double *reflection, t_parser *parser);
void			parse_transparency(double *transparency, t_parser *parser);
void			parse_brilliance(double *brilliance, t_parser *parser);
void			parse_rectangle(t_env *env, t_parser *parser);
void			parse_rectangle_check(t_rectangle *rectangle);
void			parse_cube(t_env *env, t_parser *parser);
void			parse_cube_check(t_cube *cube);
void			parse_pentagon(t_env *env, t_parser *parser);
void			parse_pentagon_check(t_pentagon *pentagon);
void			parse_hexagon(t_env *env, t_parser *parser);
void			parse_hexagon_check(t_hexagon *hexagon);
void			parse_pyramid(t_env *env, t_parser *parser);
void			parse_pyramid_check(t_pyramid *pyramid);
void			parse_tetrahedron(t_env *env, t_parser *parser);
void			parse_tetrahedron_check(t_tetrahedron *tetrahedron);
void			parse_octahedron(t_env *env, t_parser *parser);
void			parse_octahedron_check(t_octahedron *octahedron);
void			parse_obj(t_env *env, t_parser *parser);
void			parse_obj_check(t_obj *obj);
void			rectangle_add(t_env *env, t_rectangle *rectangle);
void			rectangle_free(t_rectangle *rectangle);
void			cube_add(t_env *env, t_cube *cube);
void			cube_add_regular(t_cube *cube);
void			cube_add_rotate(t_cube *cube);
void			cube_add_moves(t_cube *cube);
t_vector		*cube_add_point_1(t_cube *cube, int face);
t_vector		*cube_add_point_2(t_cube *cube, int face);
t_vector		*cube_add_point_3(t_cube *cube, int face);
t_vector		*cube_add_point_4(t_cube *cube, int face);
void			cube_free(t_cube *cube);
void			pentagon_add(t_env *env, t_pentagon *pentagon);
void			pentagon_add_regular(t_pentagon *pentagon);
void			pentagon_add_rotate(t_pentagon *pentagon);
void			pentagon_add_moves(t_pentagon *petagon);
void			pentagon_free(t_pentagon *pentagon);
void			hexagon_add(t_env *env, t_hexagon *hexagon);
void			hexagon_add_regular(t_hexagon *hexagon);
void			hexagon_add_rotate(t_hexagon *hexagon);
void			hexagon_add_moves(t_hexagon *hexagon);
void			hexagon_free(t_hexagon *hexagon);
void			pyramid_add(t_env *env, t_pyramid *pyramid);
void			pyramid_add_regular(t_pyramid *pyramid);
void			pyramid_add_rotate(t_pyramid *pyramid);
void			pyramid_add_moves(t_pyramid *pyramid);
void			pyramid_free(t_pyramid *pyramid);
void			tetrahedron_add(t_env *env, t_tetrahedron *tetrahedron);
void			tetrahedron_add_regular(t_tetrahedron *tetrahedron);
void			tetrahedron_add_rotate(t_tetrahedron *tetrahedron);
void			tetrahedron_add_moves(t_tetrahedron *tetrahedron);
void			tetrahedron_free(t_tetrahedron *tetrahedron);
void			octahedron_add(t_env *env, t_octahedron *octahedron);
void			octahedron_add_regular(t_octahedron *octahedron);
void			octahedron_add_rotate(t_octahedron *octahedron);
void			octahedron_add_moves(t_octahedron *octahedron);
void			octahedron_free(t_octahedron *octahedron);
void			obj_add(t_env *env, t_obj *obj);
void			obj_add_rotate(t_obj *obj, t_obj_file *file);
void			obj_add_moves(t_obj *obj, t_obj_file *file);
t_obj_file		*obj_parse_file(char *file);
void			obj_free(t_obj *obj);
void			set_triangle_vectors(t_object *t, t_vector *v1
		, t_vector *v2, t_vector *v3);

#endif
