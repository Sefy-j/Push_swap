SRCS	= push_swap.c ft_listutils.c ft_utils.c ft_split.c ft_pushswaputils.c ft_pushswapextrautils.c \
		ft_parsearg.c ft_movements.c ft_listextra.c ft_utilsparse.c ft_algorithm.c ft_smallalgo.c ft_normalize.c

OBJS	= ${SRCS:.c=.o}

SRCSB	= 

OBJB	= ${SRCSB:.c=.o}

PATHBON	= bonus

NAME	= push_swap

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} -o $(NAME) $(OBJS)

bonus:		
			@make -C ${PATHBON}

all:		${NAME}

clean:
				@make clean -C ${PATHBON}
				${RM} ${OBJS} ${OBJB}

fclean: 	clean
				@make fclean -C ${PATHBON}
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus
