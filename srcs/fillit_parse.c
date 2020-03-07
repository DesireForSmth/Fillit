/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:36:31 by mcarc             #+#    #+#             */
/*   Updated: 2019/11/21 17:22:25 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_coordinates_setter(t_list *list, int j)
{
	t_list		*tmp;

	tmp = list;
	j = tmp->m[0];
	tmp->m[0] = 0;
	tmp->m[2] -= j;
	tmp->m[4] -= j;
	tmp->m[6] -= j;
	j = tmp->m[1];
	tmp->m[1] = 0;
	tmp->m[3] -= j;
	tmp->m[5] -= j;
	tmp->m[7] -= j;
}

void			ft_coordinates(t_list *list)
{
	int			i;
	int			j;
	t_list		*tmp;

	tmp = list;
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (tmp->tetri[i] == '#')
		{
			tmp->m[j] = i / 5;
			tmp->m[j + 1] = i % 5;
			j += 2;
		}
		i++;
	}
	ft_coordinates_setter(tmp, j);
}

int				tetramino_parse(int fd, char *str)
{
	char		buffer;
	int			i;
	char		*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * 21);
	tmp[20] = '\0';
	while (i < 20)
	{
		if (read(fd, &buffer, 1) <= 0)
		{
			free(tmp);
			return (0);
		}
		if (!char_check(i + 1, buffer))
		{
			free(tmp);
			return (2);
		}
		tmp[i] = buffer;
		i++;
	}
	ft_memcpy(str, tmp, 21);
	free(tmp);
	return (1);
}

int				flag_checker(int flag, int flag1, char buffer)
{
	if (flag1 == 0 && buffer == '\n')
		return (0);
	if (flag1 == 2)
		return (0);
	if (!flag)
		return (0);
	return (1);
}

t_list			*fillit_parse(int fd)
{
	char		*t_s;
	char		b;
	t_list		*head;
	int			f;
	int			f1;

	head = NULL;
	f = 0;
	if (!(t_s = (char *)malloc(sizeof(char) * 21)))
		return (0);
	while ((f1 = tetramino_parse(fd, t_s)) != 0 && f1 != 2 && f++ >= 0)
	{
		b = 'a';
		read(fd, &b, 1);
		if (!check_tetri(t_s) || !fillit_lst(&head, t_s)
		|| (b != '\n' && b != '\0' && b != 'a'))
		{
			free(t_s);
			return (0);
		}
		ft_bzero(t_s, 21);
	}
	read(fd, &b, 1);
	free(t_s);
	return (flag_checker(f, f1, b) ? head : 0);
}
