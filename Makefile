LIBFT_C = ./libft/*.c

LIBFT_H = ./libft/libft.h

LIBA = libft.a

NAME = push_swap

NAME_CH = checker

HEADER = push_swap.h

HEADER_CH = ./bonus/push_swap_bonus.h

HEADER_LIBA = ./libft/libft.h

HEADER_GNL = ./gnl/get_next_line.h

SRCS	= push_swap.c \
		0_parsing_and_filling_args.c \
		1_validate_and_fill.c \
		2_func_to_fill_stack_a.c \
		3_indexation.c \
		4_markups_ind.c \
		5_init_keep_in_a_ind.c \
		6_from_a_to_b.c \
		7_0_from_b_to_a.c \
		7_1_small_ind_calculate.c \
		7_2_add_func_for_small_ind.c \
		8_small_ind_in_stack.c \
		8_0_small_ind_rr_rrr.c \
		8_1_small_ind_a_b_in_diff_halfs.c \
		9_only_big_ind_left.c \
		9_0_bigger_ind_recalculate_moves_for_a.c \
		9_1_big_ind_rr_rrr.c \
		9_2_big_ind_a_b_in_diff_halfs.c \
		9_3_add_func_big_ind.c \
		./commands/push.c \
		./commands/rotate.c \
		./commands/reverse_rotate.c \
		./commands/swap.c \
		error_case.c
		
SRCS_СH	= ./bonus/checker.c \
		./bonus/check_line_and_stacks.c \
		0_parsing_and_filling_args.c \
		1_validate_and_fill.c \
		2_func_to_fill_stack_a.c \
		3_indexation.c \
		./commands/push.c \
		./commands/rotate.c \
		./commands/reverse_rotate.c \
		./commands/swap.c \
		error_case.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		./bonus/validation.c

OBJS	= ${SRCS:.c=.o}

OBJS_CH	= ${SRCS_СH:.c=.o}

RM	= rm -rf

AR 	= ar rc

CC	= gcc -g

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: ${NAME}

compile_libft: ${LIBFT_A}

${LIBA}: ${LIBFT_C} ${LIBFT_H}
			cd ./libft; \
			make; \
			mv ${LIBA} ../; \
			cd ./libft; \
			make clean
	
#${NAME}: ${OBJS} ${HEADER}
#		 ${CC} -g -o ${NAME} ${OBJS} ${LIBA}

${NAME}: ${LIBA} ${OBJS} ${HEADER} 
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBA} 


${NAME_CH}: ${LIBA} ${OBJS_CH} ${HEADER} ${HEADER_CH} ${HEADER_GNL}
			${CC} ${CFLAGS} -o ${NAME_CH} ${OBJS_CH} ${LIBA} 

bonus: ${NAME_CH}

norm: ${SRCS} ${LIBFT_C} ${SRCS_СH} ${HEADER} ${HEADER_LIBA} ${HEADER_CH}
		norminette ${SRCS} ${LIBFT_C} ${HEADER} ${HEADER_LIBA} ${SRCS_СH} ${HEADER_CH}

clean:
		${RM} ${OBJS} ${OBJS_CH}

fclean:	clean
		${RM} ${NAME} ${NAME_CH} ${LIBA}

re:		fclean all

.PHONY: all re clean fclean all compile_libft bonus norm