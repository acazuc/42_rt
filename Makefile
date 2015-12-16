# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2015/12/15 14:41:03 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

CFLAGS = -Wall -Wextra -Werror -Ofast

CC = gcc

HDIR = headers/

HEADERS = $(HDIR)console.h \
		  $(HDIR)env.h \
		  $(HDIR)prototypes.h \
		  $(HDIR)rtv1.h \
		  $(HDIR)window.h \
		  $(HDIR)includes.h \
		  $(HDIR)object.h \
		  $(HDIR)object_list.h \
		  $(HDIR)object_type.h \
		  $(HDIR)vector.h \
		  $(HDIR)functions.h \
		  $(HDIR)ray.h \
		  $(HDIR)light.h \
		  $(HDIR)point.h \
		  $(HDIR)trinome.h \
		  $(HDIR)light_list.h \
		  $(HDIR)colors.h

DIR = srcs/

SRCS = $(DIR)main.c \
	   $(DIR)pixel_put.c \
	   $(DIR)error_quit.c \
	   $(DIR)draw_reset.c \
	   $(DIR)draw.c \
	   $(DIR)trace.c \
	   $(DIR)env_init.c \
	   $(DIR)window_init.c \
	   $(DIR)expose_listener.c \
	   $(DIR)display.c \
	   $(DIR)object_create.c \
	   $(DIR)object_add.c \
	   $(DIR)vector_create.c \
	   $(DIR)distance_3d.c \
	   $(DIR)key_listener.c \
	   $(DIR)point_create.c \
	   $(DIR)create_sphere.c \
	   $(DIR)create_cylinder.c \
	   $(DIR)create_cone.c \
	   $(DIR)collide.c \
	   $(DIR)collide_sphere.c \
	   $(DIR)collide_cylinder.c \
	   $(DIR)collide_cone.c \
	   $(DIR)ray_create.c \
	   $(DIR)vector_rotate.c \
	   $(DIR)vector_rotation.c \
	   $(DIR)light_create.c \
	   $(DIR)light_add.c \
	   $(DIR)vector_size.c \
	   $(DIR)color_create.c \
	   $(DIR)vector_normalize.c \
	   $(DIR)color_getters.c \
	   $(DIR)light_level.c \
	   $(DIR)ray_free.c \
	   $(DIR)collision_create.c \
	   $(DIR)color_factor.c \
	   $(DIR)vector_equals.c \
	   $(DIR)vector_multiply.c \
	   $(DIR)vector_angle.c \
	   $(DIR)normal.c \
	   $(DIR)normal_sphere.c \
	   $(DIR)normal_cylinder.c

OBJS = $(SRCS:.c=.o)

LIBRARY = -lm -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
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
	@Make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)

%.o: %.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $<

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
