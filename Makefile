# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/10/13 15:29:35 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

CFLAGS = -Wall -Wextra -Werror -Ofast

CC = gcc

INCLUDES_PATH = include/

SRCS_PATH = src/

SRCS_NAME = main.c \
			pixel_put.c \
			error_quit.c \
			draw_reset.c \
			draw.c \
			trace.c \
			env_init.c \
			window_init.c \
			expose_listener.c \
			display.c \
			object_create.c \
			object_add.c \
			vector_create.c \
			distance_3d.c \
			key_listener.c \
			point_create.c \
			create_sphere.c \
			create_cylinder.c \
			create_cone.c \
			create_plane.c \
			create_triangle.c \
			create_rectangle.c \
			create_cube.c \
			create_pentagon.c \
			create_hexagon.c \
			create_pyramid.c \
			create_tetrahedron.c \
			create_octahedron.c \
			create_obj.c \
			collide.c \
			collide_sphere.c \
			collide_cylinder.c \
			collide_cone.c \
			collide_plane.c \
			collide_triangle.c \
			ray_create.c \
			vector_rotate.c \
			vector_rotation.c \
			light_create.c \
			light_add.c \
			vector_size.c \
			vector_dot.c \
			vector_dup.c \
			color_create.c \
			vector_normalize.c \
			color_getters.c \
			light_level.c \
			ray_free.c \
			collision_create.c \
			collision_free.c \
			color_factor.c \
			vector_equals.c \
			vector_multiply.c \
			vector_angle.c \
			color_mask_create.c \
			color_mask.c \
			trinome_create.c \
			get_ray_color.c \
			get_reflection_ray.c \
			color_add.c \
			worker.c \
			get_transparency_ray.c \
			light_level_mask.c \
			parse_scene.c \
			parse_object.c \
			parse_light.c \
			parse_color.c \
			parse_camera.c \
			parse_camera_position.c \
			parse_camera_rotation.c \
			get_next_line.c \
			epoch_millis.c \
			free_objects.c \
			free_lights.c \
			light_data_create.c \
			light_data_free.c \
			parse_object_check.c \
			parse_light_check.c \
			parse_light_position.c \
			parse_light_mask.c \
			parse_valid_number.c \
			parse_object_position.c \
			parse_object_rotation.c \
			parse_object_dimensions.c \
			parse_error.c \
			parse_triangle.c \
			parse_triangle_point.c \
			parse_ambient_light.c \
			parse_window.c \
			parse_double.c \
			parse_point.c \
			parse_reflection.c \
			parse_transparency.c \
			parse_brilliance.c \
			parse_rectangle.c \
			parse_rectangle_check.c \
			parse_cube.c \
			parse_cube_check.c \
			parse_pentagon.c \
			parse_pentagon_check.c \
			parse_hexagon.c \
			parse_hexagon_check.c \
			parse_pyramid.c \
			parse_pyramid_check.c \
			parse_tetrahedron.c \
			parse_tetrahedron_check.c \
			parse_octahedron.c \
			parse_octahedron_check.c \
			parse_octahedron.c \
			parse_octahedron_check.c \
			parse_obj.c \
			parse_obj_check.c \
			rectangle_add.c \
			rectangle_free.c \
			cube_add.c \
			cube_add_regular.c \
			cube_add_rotate.c \
			cube_add_moves.c \
			cube_add_points.c \
			cube_free.c \
			pentagon_add.c \
			pentagon_add_regular.c \
			pentagon_add_rotate.c \
			pentagon_add_moves.c \
			pentagon_free.c \
			hexagon_add.c \
			hexagon_add_regular.c \
			hexagon_add_rotate.c \
			hexagon_add_moves.c \
			hexagon_free.c \
			pyramid_add.c \
			pyramid_add_regular.c \
			pyramid_add_rotate.c \
			pyramid_add_moves.c \
			pyramid_free.c \
			tetrahedron_add.c \
			tetrahedron_add_regular.c \
			tetrahedron_add_rotate.c \
			tetrahedron_add_moves.c \
			tetrahedron_free.c \
			octahedron_add.c \
			octahedron_add_regular.c \
			octahedron_add_rotate.c \
			octahedron_add_moves.c \
			octahedron_free.c \
			obj_add.c \
			obj_add_moves.c \
			obj_add_rotate.c \
			obj_parse_file.c \
			obj_free.c \
			set_triangle_vectors.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lmlx -L libft -lft -framework OpenGL -framework AppKit

all: odir $(NAME)

$(NAME): $(OBJS)
	@Make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)
clean:
	@Make clean -C libft
	@echo " - Clearing objects files"
	@rm -f $(OBJS)

fclean: clean
	@Make fclean -C libft
	@echo " - Clearing executable file"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
