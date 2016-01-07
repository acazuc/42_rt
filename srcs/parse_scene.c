/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 08:58:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/07 16:44:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		do_create_object(t_object **object, char *str)
{
	if (!ft_strcmp(str, "sphere"))
		*object = create_sphere();
	else if (!ft_strcmp(str, "cylinder"))
		*object = create_cylinder();
	else if (!ft_strcmp(str, "cone"))
		*object = create_cone();
	else if (!ft_strcmp(str, "plane"))
		*object = create_plane();
}

static void		do_parse(t_env *env, char **datas)
{
	t_object	*object;
	t_light		*light;

	object = NULL;
	light = NULL;
	if (!ft_strcmp(datas[0], "sphere") || !ft_strcmp(datas[0], "cylinder") || !ft_strcmp(datas[0], "cone") || !ft_strcmp(datas[0], "plane"))
	{
		do_create_object(&object, datas[0]);
		parse_object(object, datas);
		object_add(env, object);
	}
	else if (!ft_strcmp(datas[0], "light"))
	{
		light = light_create();
		parse_light(light, datas);
		light_add(env, light);
	}
	else if (!ft_strcmp(datas[0], "camera"))
		parse_camera(env, datas);
	else
		error_quit("Invalid line in scene");
}

static void		parse_line(t_env *env, char *line)
{
	char	**datas;
	int		len;

	if (ft_strlen(line) > 0)
	{
		if (line[0] != '#')
		{
			datas = ft_strsplit(line, '\t');
			len = 0;
			while (datas[len])
				len++;
			if (len > 0)
				do_parse(env, datas);
			len = 0;
			while (datas[len])
				free(datas[len++]);
		}
	}
}

void	parse_scene(t_env *env, char *file)
{
	char	*line;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_quit("Failed to open scene file");
	while (get_next_line(fd, &line) > 0)
	{
		parse_line(env, line);
		free(line);
	}
	close(fd);
}
