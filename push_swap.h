#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "./libft/libft_copy/libft.h"

typedef struct s_stack_a
{
	int	number;
	int	num_rage;
	struct s_stack_a *next;
}				t_stack_a


int		error_case(char *s);
void	check_input(char **array);
void	adding_digits_to_stack(char **argv, t_stacks *stack);

#endif