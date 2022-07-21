/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:34:47 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/06/21 13:56:33 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <limits.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_min
{
	int		num;
	int		lastnum;
	int		posa;
	int		size;
	int		maxa;
	int		mina;
	int		pos;
}	t_min;

enum {
	ERRGENERAL = 1,
	ERRNOTNUM = 2,
	ERRNUMREPEAT = 3,
	ERREMPTARG = 4,
	ERRTOOBIG = 5
};

enum {
	MIN = 0,
	MINPOS = 1,
	OLDMIN = 2,
	COPYNUM = 3,
	MAX = 4,
	MAXPOS = 5
};

enum {
	MAXIM = 0,
	OLDMAXIM = 1,
	POS = 2,
	SIZE = 3,
};

enum {
	A = 0,
	B = 1
};

t_list				*ft_lstnew(int num);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_freematrix(char **matrix);
void				ft_errors(int error, char *name);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_lstclear(t_list **lst);
void				ft_lstdelone(t_list *lst);
void				ft_s(t_list *a, char c);
void				ft_ss(t_list *a, t_list *b, char c);
void				ft_lstclearone(t_list **lst);
void				ft_p(t_list **listto, t_list **listfrom, char c);
void				ft_r(t_list **a, char c);
void				ft_rr(t_list **a, t_list **b, char c);
void				ft_ir(t_list **a, char c);
void				ft_irr(t_list **a, t_list **b, char c);
void				ft_startpos(t_list **a, t_list **b);
void				ft_solve(t_list **a, t_list **b, int *toswap);
void				ft_movetofirst(t_list **lst, int pos, int size);
void				ft_printlist(t_list *a);
void				ft_smallalgo(t_list **a, t_list **b);
char				*ft_itoa(int n);
char				**ft_split(char const *str, char c);
char				*ft_strdup(const char *src);
int					ft_isdigit(int c);
int					ft_lstsize(t_list *lst);
int					ft_min(t_list *lst, int *min);
int					*ft_checkargv(int argc, char **argv, int *total);
int					*ft_normalize(int *nums, int total);
int					*ft_copylist(t_list **a, int *nums, int total);
size_t				ft_strlen(const char *str);
long long int		ft_atoipushswap(const char *str);

#endif
