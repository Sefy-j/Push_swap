SRCS	= checker.c ft_listutils.c ft_utils.c ft_split.c ft_pushswaputils.c ft_parsearg.c ft_checkmove.c\
		ft_movements.c ft_listextra.c ft_utilsparse.c get_next_line.c get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

SRCSB	=

OBJB	= ${SRCSB:.c=.o}

NAME	= ../checker

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} -o $(NAME) $(OBJS)

bonus:		all ${OBJB}
				@make OBJS="${OBJB}"

all:		${NAME}

clean:
				${RM} ${OBJS} ${OBJB}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus
