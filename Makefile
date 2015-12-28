# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2015/12/28 11:31:16 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

CFLAGS = -Wall -Wextra -Werror -Ofast

CC = gcc

INCLUDES_PATH = includes/

INCLUDES_NAME = console.h \
		  		env.h \
				prototypes.h \
				rtv1.h \
				window.h \
				includes.h \
				object.h \
				object_list.h \
		 		object_type.h \
		 		vector.h \
		 		functions.h \
		 		ray.h \
		 		light.h \
		 		point.h \
		 		trinome.h \
		 		light_list.h \
		 		colors.h \
		 		color_mask.h \
		 		collision.h

INCLUDES = $(addprefix $(INCLUDES_PATH), $(INCLUDES_NAME))

SRCS_PATH = srcs/

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
	  		collide.c \
	  		collide_sphere.c \
	  		collide_cylinder.c \
	  		collide_cone.c \
	  		ray_create.c \
	  		vector_rotate.c \
	  		vector_rotation.c \
	 		light_create.c \
	 		light_add.c \
	 		vector_size.c \
	  		color_create.c \
	  		vector_normalize.c \
	 		color_getters.c \
	 		light_level.c \
	  		ray_free.c \
	  		collision_create.c \
	  		color_factor.c \
	  		vector_equals.c \
	  		vector_multiply.c \
	   		vector_angle.c \
	  		normal.c \
	  		normal_sphere.c \
	  		normal_cylinder.c \
	  		color_mask_create.c \
	   		color_mask.c \
	  		trinome_create.c \
	  		get_ray_color.c \
	   		get_reflection_ray.c \
	   		color_add.c \
	   		worker.c \
	  		get_transparency_ray.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@Make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)
	@echo "\033[1;32m"
	@echo "                                      AKEFILEMA                         (c) Tchang     "
	@echo "                                  KEFILEMAKEFILEMAK                                    "
	@echo "                              EFILEMAKEFILEMAKEFILEMAK                                 "
	@echo "                      EFILEMAKEFILEMA           KEFILEMA                               "
	@echo "                   KEFILEMAKEFIL                  EMAKEFI                              "
	@echo "                 LEMAKEFILEMAKEF                   ILEMAK                              "
	@echo "                 EFILEMAKEFILEMAK                   EFILE          COMPILATION         "
	@echo "                 MAKEFILEMAK EFILEM    AKEFILEMAKE  FILEM             DONE             "
	@echo "                 AKEFILEMAKEFILEMAKE FILEMAKEFI  MAK EFIL        CONGRATULATION        "
	@echo "                 EMAKEFILEMAKEFILE  MAKEFILEMAK  ILEMAKEF        ______ _______        "
	@echo "                ILEMA  KEFILEMAKEF  ILEMAKEFI    KEFILEMA             |/               "
	@echo "               KEFILEMAKEFILEMAKEFI LEMAKEFI    AKEFILEMA                              "
	@echo "              KEFILEMAKEFILEMAKEF   ILEMAKEFILEMAKEFILEMA                              "
	@echo "             KEFILEMAKEFILEMAKEFILEMAKEFILEMAKEFI  LEMAK                               "
	@echo "            EFILE          MAKEFILEMAKEFILEMA     KEFILE                               "
	@echo "           MAKEF                      ILEMAKE     FILEMA                               "
	@echo "          KEFILE                                 MAKEFI                                "
	@echo "         LEMAKE                                 FILEMA                                 "
	@echo "        KEFILE                                  MAKEFI                                 "
	@echo "        LEMAK                      EFIL        EMAKEF                                  "
	@echo "        ILEM                      AKEFI LEM   AKEFIL                                   "
	@echo "        EMAK                      EFILEMAKEF  ILEMA                         KEFILEMAK  "
	@echo "       EFILE                      MAKEFILEM  AKEFI                        LEMAKEFILEMA "
	@echo "       KEFIL                     EMAKEFILEM AKEFI                       LEMAKE    FILE "
	@echo "       MAKEF                     ILEMAKEFI  LEMAK                     EFILEMA    KEFIL "
	@echo "       EMAKE                    FILEMAKEF  ILEMAK                   EFILEMA     KEFIL  "
	@echo "       EMAKE                    FILEMAKE   FILEMAKEFILEMAKEFILE   MAKEFIL     EMAKE    "
	@echo "        FILE                   MAKEFILE    MAKEFILEMAKEFILEMAKEFILEMAKE      FILEM     "
	@echo "        AKEF                   ILEMAKE     FILEM   AKEFI   LEMAKEFILE      MAKEFI      "
	@echo "        LEMA                  KEFILEMA      KEF   ILEMAKEFILEMAKEFI      LEMAKE        "
	@echo "        FILEM               AKEFI LEMAK         EFILEMAKEFILEMAKEF     ILEMAKE         "
	@echo "         FILE             MAKEF  ILEMAKE         FILEMAKEFILEMAKEFIL   EMAKEFIL        "
	@echo "         EMAKE            FILEMAKEFILEMA                     KEFILEMA    KEFILEMAK     "
	@echo "          EFILE            MAKEFILEMAKE              FILE       MAKEFI  LEMA KEFIL     "
	@echo "          EMAKEF              ILEM                   AKEF        ILEMAK  EFILEMAK      "
	@echo "           EFILEM                                AKE              FILEM    AKEF        "
	@echo "            ILEMAKEF                            ILEM              AKEFI     LEMA       "
	@echo "               KEFILEM                          AKEF              ILEMAKEFILEMAK       "
	@echo "     EFI        LEMAKEFILE                       MAKE           FILEMAKEFILEMAK        "
	@echo "    EFILEMA    KEFILEMAKEFILEMAK                  EFI         LEMAKEF    I             "
	@echo "    LEMAKEFILEMAKE FILEMAKEFILEMAKEFILEM           AKEF    ILEMAKE                     "
	@echo "    FILE MAKEFILEMAKEFI    LEMAKEFILEMAKEF ILEMAKEFILEMAKEFILEMA                       "
	@echo "     KEFI  LEMAKEFILE         MAKEFILEMAK EFILEMAKEFILEMAKEFI                          "
	@echo "      LEMA   KEFILE         MAKEFILEMAKE FILEM AKEFILEMAKE                             "
	@echo "       FILEMAKEFI           LEMAKEFILEM  AKEF                                          "
	@echo "        ILEMAKE              FILEMAKE   FILE                                           "
	@echo "          MAK                EFILEM    AKEF                                            "
	@echo "                              ILEMAK  EFIL                                             "
	@echo "                               EMAKEFILEM                                              "
	@echo "                                 AKEFILE                                               "
	@echo "                                   MAK                                                 "
	@echo "\033[1;0m"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

.PHONY: clean fclean re norme

norme:
	@norminette $(SRCS) $(HEADERS)

clean:
	@Make clean -C libft
	@echo " - Clearing objects files"
	@rm -f $(OBJS)

fclean: clean
	@Make fclean -C libft
	@echo " - Clearing executable file"
	@rm -f $(NAME)

re: fclean all
