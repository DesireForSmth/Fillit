/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:30:31 by wscallop          #+#    #+#             */
/*   Updated: 2019/12/09 15:06:24 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_p(char **mass, int i, int j, t_list list)
{
	int				index;
	int				flag;

	flag = 0;
	index = 0;
	while (index < 7)
	{
		if (mass[i + list.m[index]][j + list.m[index + 1]] == '.')
			flag++;
		index += 2;
	}
	if (flag == 4)
	{
		index = 0;
		while (index < 7)
		{
			mass[i + list.m[index]][j + list.m[index + 1]] = list.chr;
			index += 2;
		}
		return (1);
	}
	return (0);
}

static int			ft_check_free_cell(char **mass, int side, int *i, int *j)
{
	*i = 0;
	while (*i < side)
	{
		*j = 0;
		while (*j < side)
		{
			if (mass[*i][*j] == '.')
				return (1);
			(*j)++;
		}
		(*i)++;
	}
	return (0);
}

static void			ft_del_tetri(char **mass, int i, int j, t_list list)
{
	int		index;

	index = 0;
	while (index < 7)
	{
		mass[i + list.m[index]][j + list.m[index + 1]] = '.';
		index += 2;
	}
}

static int			ft_fillit_input(char **m, int s, t_list *l, int i)
{
	int				j;

	i = 0;
	j = 0;
	if (!ft_check_free_cell(m, s, &i, &j) || !l)
		return (1);
	while (i < s && j < s && l)
	{
		if (i + l->m[6] <= s - 1 && j + l->m[7] <= s - 1 && ft_p(m, i, j, *l))
		{
			if (ft_fillit_input(m, s, l->next, i))
				return (1);
			ft_del_tetri(m, i, j, *l);
		}
		if (j == s - 1 && i == s - 1)
			return (0);
		else if (j == s - 1 && i != s - 1)
		{
			j = 0;
			i++;
		}
		else
			j = j < (s - 1) ? j + 1 : j + 0;
	}
	return (0);
}

void				ft_fillit_solve(t_list *list)
{
	int				index;
	int				value;
	char			**mass;
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = list;
	index = 0;
	value = ft_fillit_val_sqrt(ft_fillit_value(tmp));
	mass = ft_fillit_past(value);
	if (!mass)
		return ;
	while (!ft_fillit_input(mass, value, list, i))
	{
		ft_freedom(mass, value);
		value++;
		mass = ft_fillit_past(value);
		if (!mass)
			return ;
	}
	fillit_mass_print(mass, value);
	ft_freedom(mass, value);
}
