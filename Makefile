LIBFT_C = ./libft/*.c

LIBA = libft.a

NAME = push_swap

HEADER = push_swap.h

HEADER_LIBA = ./libft/libft.h

SRCS	= main.c \
		1_check_input.c \
		2_filling_stack_a.c \
		3_check_if_stack_is_sorted.c \
		4_list_size.c \
		5_indexation.c \
		6_markups_greater.c \
		7_init_keep_in_a_greater.c \
		8_from_a_to_b.c \
		./commands/push.c \
		./commands/rotate.c \
		./commands/swap.c \
		error_case.c
		

SRCS_2	= ./libft/ft_atoi.c

OBJS	= ${SRCS:.c=.o}

OBJS_2	= ${SRCS_2:.c=.o}

RM	= rm -rf

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

${NAME}: ${LIBA} ${HEADER} ${OBJS} ${OBJS_2}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_2} ${LIBA} 

clean:
		${RM} ${OBJS} ${OBJS_2}

fclean:	clean
		${RM} ${NAME} a.out ${LIBA}

re:		fclean all

.PHONY: re clean fclean all compile_libft compile_mlx