/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:30:47 by mcarc             #+#    #+#             */
/*   Updated: 2019/11/21 18:35:55 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	char			*tetri;
	int				m[8];
	char			chr;
	struct s_list	*next;
}					t_list;

void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				fillit_mass_print(char **mass, int value);
int					tetramino_parse(int fd, char *str);
t_list				*fillit_parse(int fd);
int					char_check(int i, char check);
size_t				c_p(char a);
size_t				link_counter(char *tmp);
size_t				square_counter(char *str);
int					check_tetri(char *tmp);
t_list				*fillit_lstnew(char *content);
int					fillit_lstpushback(t_list *head, char *content);
void				fillit_lstdelone(t_list **tmp);
void				fillit_lstdel(t_list **head);
t_list				*fillit_lst(t_list **head, char *content);
int					ft_fillit_val_sqrt(int grid);
void				ft_freedom(char **mass, int fl);
int					ft_fillit_value(t_list *list);
char				**ft_fillit_first(int fl);
char				**ft_fillit_past(int counter);
void				ft_fillit_solve(t_list *list);
void				ft_coordinates(t_list *list);
void				fillit_error(t_list *head);
void				array_init(int array[4]);
void				min_max(int i, int array[4]);
void				fillit_shift_matrix(char *tetri, int i, int array[4]);
void				fillit_shift_tetri(char *tetri);
void				fillit_shift(t_list *head);
size_t				ft_strlen(const char *s);
void				lst_print(t_list *head);
int					end_val(char str[3]);
void				ft_coordinates_setter(t_list *list, int j);
int					flag_checker(int flag, int flag1, char buffer);

#endif
