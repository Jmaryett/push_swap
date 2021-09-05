#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "./libft_42_school/libft.h"

typedef struct s_stacks
{
	int	stack_a[1000];
	int	stack_b[1000];
}				t_stacks;

int		error_case(char *s);
void	check_input(char **array);
void	adding_digits_to_stack(char **argv, t_stacks *stack);


#endif