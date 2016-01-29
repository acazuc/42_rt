/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 08:58:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 13:22:40 by acazuc           ###   ########.fr       */
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

static void		do_parse_2(t_env *env, t_parser *parser)
{
	t_object	*object;

	if (!ft_strcmp(parser->datas[0], "ambient_light"))
		parse_ambient_light(env, parser);
	else if (!ft_strcmp(parser->datas[0], "triangle"))
	{
		object = create_triangle();
		parse_triangle(object, parser);
		object_add(env, object);
	}
	else
		parse_error(parser, "Unknown line in scene");
}

static void		do_parse(t_env *env, t_parser *parser)
{
	t_object	*object;
	t_light		*light;

	if (!ft_strcmp(parser->datas[0], "sphere")
			|| !ft_strcmp(parser->datas[0], "cylinder")
			|| !ft_strcmp(parser->datas[0], "cone")
			|| !ft_strcmp(parser->datas[0], "plane"))
	{
		do_create_object(&object, parser->datas[0]);
		parse_object(object, parser);
		object_add(env, object);
	}
	else if (!ft_strcmp(parser->datas[0], "light"))
	{
		light = light_create();
		parse_light(light, parser);
		light_add(env, light);
	}
	else if (!ft_strcmp(parser->datas[0], "camera"))
		parse_camera(env, parser);
	else if (!ft_strcmp(parser->datas[0], "window"))
		parse_window(env, parser);
	else
		do_parse_2(env, parser);
}

static void		parse_line(t_env *env, char *file, char *line, int line_number)
{
	t_parser	parser;
	int			len;

	if (ft_strlen(line) > 0)
	{
		if (line[0] != '#')
		{
			parser.line = line_number;
			parser.file = file;
			parser.datas = ft_strsplit(line, '\t');
			len = 0;
			while (parser.datas[len])
				len++;
			if (len > 0)
				do_parse(env, &parser);
			len = 0;
			while (parser.datas[len])
				free(parser.datas[len++]);
		}
	}
}

void			parse_scene(t_env *env, char *file)
{
	char	*line;
	int		rd;
	int		fd;
	int		i;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_quit("Failed to open scene file");
	i = 1;
	while ((rd = get_next_line(fd, &line)) > 0)
	{
		parse_line(env, file, line, i);
		i++;
		free(line);
	}
	if (rd == -1)
		error_quit("Invalid scene file");
	close(fd);
}
