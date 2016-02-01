/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parse_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:39:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 15:41:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		push_vertex(t_obj_file *file, t_vector *v)
{
	t_obj_vertex_list	*new;
	t_obj_vertex_list	*lst;

	if (!(new = malloc(sizeof(*new))))
		error_quit("Failed to malloc new obj vertex");
	new->vertex = v;
	new->next = NULL;
	lst = file->vertex;
	if (!lst)
	{
		file->vertex = new;
		return ;
	}
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

static void		push_face(t_obj_file *file, int v1, int v2, int v3)
{
	t_obj_face_list		*new;
	t_obj_face_list		*lst;

	if (!(new = malloc(sizeof(*new))))
		error_quit("Failed to malloc new obj face");
	new->v1 = v1;
	new->v2 = v2;
	new->v3 = v3;
	new->next = NULL;
	lst = file->faces;
	if (!lst)
	{
		file->faces = new;
		return ;
	}
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

static void		parse_vertex(t_obj_file *file, char *line)
{
	t_vector	*vector;
	char		**datas;

	if (!(datas = ft_strsplit(line, ' ')))
		error_quit("Failed to split obj line");
	if (!datas[0] || !datas[1] || !datas[2] || !datas[3] || datas[4])
		error_quit("Invalid obj file (vertex split size)");
	if (!parse_valid_number(datas[1]) || !parse_valid_number(datas[2])
			|| !parse_valid_number(datas[3]))
		error_quit("Invalid obj file (vertex coord format)");
	vector = vector_create();
	vector->x = ft_atod(datas[1]);
	vector->y = ft_atod(datas[2]);
	vector->z = ft_atod(datas[3]);
	push_vertex(file, vector);
}

static void		parse_face(t_obj_file *file, char *line)
{
	char	**pdatas;
	char	**datas;
	int		v[3];
	int		i;

	if (!(datas = ft_strsplit(line, ' ')))
		error_quit("Failed to split obj line");
	if (!datas[0] || !datas[1] || !datas[2] || !datas[3] || datas[4])
		error_quit("Invalid obj file (face line size)");
	i = 0;
	while (i < 3)
	{
		if (!(pdatas = ft_strsplit(datas[i + 1], '/')))
			error_quit("Invalid obj file (face arg split size)");
		if (!pdatas[0])
			error_quit("Invalid obj file (face arg split size 2)");
		if (!ft_strisdigit(pdatas[0]))
			error_quit("Invalid obj file (face vertex id)");
		v[i] = ft_atoi(pdatas[0]);
		i++;
	}
	push_face(file, v[0], v[1], v[2]);
}

t_obj_file		*obj_parse_file(char *name)
{
	t_obj_file	*file;
	char		*line;
	int			rd;
	int			fd;

	if (!(file = malloc(sizeof(*file))))
		error_quit("Failed to malloc obj file struct");
	file->vertex = NULL;
	file->faces = NULL;
	if ((fd = open(name, O_RDONLY)) == -1)
		error_quit("Failed to open obj file");
	while ((rd = get_next_line(fd, &line)) == 1)
	{
		if (line[0] == 'v' && line[1] == ' ')
			parse_vertex(file, line);
		else if (line[0] == 'f' && line[1] == ' ')
			parse_face(file, line);
	}
	if (rd == -1)
		error_quit("Error while getting next line of obj file");
	close(fd);
	return (file);
}
