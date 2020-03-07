/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wscallop_try2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:55:12 by wscallop          #+#    #+#             */
/*   Updated: 2019/11/21 18:08:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_fillit_val_sqrt(int grid)
{
	int		index;

	index = 1;
	while (grid > index * index)
		index++;
	return (index);
}

int			ft_fillit_value(t_list *list)
{
	t_list	*tmp;
	int		index;
	char	chr;

	chr = 'A';
	index = 0;
	tmp = list;
	while (tmp)
	{
		index = index + 4;
		ft_coordinates(tmp);
		tmp->chr = chr;
		chr++;
		tmp = tmp->next;
	}
	return (index);
}

void		ft_freedom(char **mass, int val)
{
	int		i;

	i = 0;
	while (i < val)
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}

char		**ft_fillit_past(int counter)
{
	int		index;
	int		flag;
	char	**new_mass;

	index = 0;
	new_mass = (char **)malloc(sizeof(char *) * counter);
	if (!new_mass)
		return (NULL);
	while (counter > index)
	{
		flag = 0;
		if (!(new_mass[index] = (char *)malloc(sizeof(char) * counter)))
		{
			ft_freedom(new_mass, index);
			return (NULL);
		}
		while (counter > flag)
			new_mass[index][flag++] = '.';
		index++;
	}
	return (new_mass);
}
