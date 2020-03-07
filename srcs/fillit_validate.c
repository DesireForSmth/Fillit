/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:36:47 by mcarc             #+#    #+#             */
/*   Updated: 2019/11/25 15:55:04 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			char_check(int i, char check)
{
	if (i == 1 && check == '\n')
		return (0);
	if (i % 5 == 0 && check != '\n')
		return (0);
	else if (i % 5 != 0 && (check != '.' && check != '#'))
		return (0);
	return (1);
}

size_t		c_p(char a)
{
	if (a == '#')
		return (1);
	return (0);
}

size_t		link_counter(char *tmp)
{
	int		i;
	size_t	l;
	char	*str;

	i = -1;
	l = 0;
	str = tmp;
	while (i++ < 20)
		if (str[i] == '#')
		{
			if (i == 0)
				l += c_p(str[i + 1]) + c_p(str[i + 5]);
			else if (i < 4)
				l += c_p(str[i + 1]) + c_p(str[i - 1]) + c_p(str[i + 5]);
			else if (i == 15)
				l += c_p(str[i + 1]) + c_p(str[i - 5]);
			else if (i > 15)
				l += c_p(str[i + 1]) + c_p(str[i - 1]) + c_p(str[i - 5]);
			else if (i % 5 == 0)
				l += c_p(str[i + 1]) + c_p(str[i + 5]) + c_p(str[i - 5]);
			else
				l += c_p(str[i + 1]) + c_p(str[i - 1]) + c_p(str[i + 5])
						+ c_p(str[i - 5]);
		}
	return (l);
}

size_t		square_counter(char *str)
{
	size_t	counter;
	char	*tmp;
	int		i;

	i = 0;
	tmp = str;
	counter = 0;
	while (i < 21)
	{
		if (tmp[i] == '#')
			counter++;
		i++;
	}
	return (counter);
}

int			check_tetri(char *tmp)
{
	static int	count = 0;

	count++;
	if (count > 26)
		return (0);
	if (square_counter(tmp) == 4 && link_counter(tmp) >= 6)
		return (1);
	return (0);
}
