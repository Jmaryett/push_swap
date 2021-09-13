LIBFT_C = ./libft/*.c

LIBA = libft.a

NAME = push_swap

HEADER = push_swap.h

SRCS	= main.c \
		1_check_input.c \
		2_adding_digits_to_stack.c \
		sort_small_stack/3_algorithm_for_3.c \
		error_case.c
		
OBJS	= ${SRCS:.c=.o}

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
			cd ./libft; \
			make; \
			mv ${LIBA} ../; \
			cd ./libft; \
			make clean
	
#${NAME}: ${OBJS} ${HEADER}
#		 ${CC} -g -o ${NAME} ${OBJS} ${LIBA}

${NAME}: ${LIBA} ${HEADER} ${OBJS} 
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBA}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} a.out

re:		fclean all

.PHONY: re clean fclean all compile_libft compile_mlx