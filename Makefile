LIBFT_C = ./libft/libft_copy/*.c

LIBA = libft.a

NAME = push_swap

HEADER = push_swap.h

SRCS	= main.c \
		1_check_input.c \
		error_case.c
		

SRCS_2	= ./libft/libft_copy/ft_atoi.c

OBJS	= ${SRCS:.c=.o}

OBJS_2	= ${SRCS_2:.c=.o}

RM	= rm -f

AR 	= ar rc

CC	= gcc -g

CFLAGS	= -Wall -Wextra -Werror

 #%.o: %.c
#	 ${CC} ${CFLAGS} -Imlx -c $< -o $@ 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: ${NAME}

compile_libft: ${LIBFT_A}

${LIBA}: ${LIBFT_C}
			cd ./libft/libft_copy; \
			make; \
			mv ${LIBA} ../../; \
			cd ./libft/libft_copy; \
			make clean
	
#${NAME}: ${OBJS} ${HEADER}
#		 ${CC} -g -o ${NAME} ${OBJS} ${LIBA}

${NAME}: ${LIBA} ${HEADER} ${OBJS} ${OBJS_2}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_2} ${LIBA} 

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} a.out

re:		fclean all

.PHONY: re clean fclean all compile_libft compile_mlx