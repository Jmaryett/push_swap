LIBFT_C = ./libft/*.c

LIBA = libft.a

NAME = push_swap

HEADER = push_swap.h

HEADER_LIBA = ./libft/libft.h

SRCS	= main.c \
		0_parsing_and_filling_args.c \
		1_validate_and_fill.c \
		2_func_to_fill_stack_a.c \
		3_indexation.c \
		4_markups_greater.c \
		5_init_keep_in_a_greater.c \
		6_from_a_to_b.c \
		7_from_b_to_a.c \
		7_add_func_for_small_ind.c \
		8_0_small_ind_rotate_a_b.c \
		8_small_ind_in_stack.c \
		9_only_big_ind_left.c \
		9_0_bigger_ind_recalculate_moves_for_a.c \
		9_1_bigger_ind_rotate_a_b.c \
		./commands/push.c \
		./commands/rotate.c \
		./commands/reverse_rotate.c \
		./commands/swap.c \
		error_case.c
		

SRCS_2	= ./libft/ft_atoi.c \
			./libft/ft_split.c

OBJS	= ${SRCS:.c=.o}

OBJS_2	= ${SRCS_2:.c=.o}

RM	= rm -rf

AR 	= ar rc

CC	= gcc -g

CFLAGS	= -Wall -Wextra -Werror

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

norm: ${SRCS} ${LIBFT_C} ${HEADER} ${HEADER_LIBA}
		norminette ${SRCS} ${LIBFT_C} ${HEADER} ${HEADER_LIBA}

clean:
		${RM} ${OBJS} ${OBJS_2}

fclean:	clean
		${RM} ${NAME} a.out ${LIBA}

re:		fclean all

.PHONY: re clean fclean all compile_libft compile_mlx