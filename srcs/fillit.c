/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:25:58 by mcarc             #+#    #+#             */
/*   Updated: 2019/11/21 17:53:36 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	t_list	*head;
	int		fd;

	head = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(head = fillit_parse(fd)))
	{
		ft_putstr("error\n");
		close(fd);
		return (0);
	}
	close(fd);
	ft_fillit_solve(head);
	fillit_lstdel(&head);
	return (0);
}
