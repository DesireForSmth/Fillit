/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:01:34 by mcarc             #+#    #+#             */
/*   Updated: 2019/11/21 18:22:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void				fillit_mass_print(char **mass, int counter)
{
	int				i;
	int				j;

	i = 0;
	while (i < counter)
	{
		j = 0;
		while (j < counter)
		{
			ft_putchar(mass[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int					end_val(char str[2])
{
	if ((str[0] == '.' || str[0] == '#') && str[1] == '\n')
		return (1);
	return (0);
}
