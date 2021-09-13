#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "./libft/libft.h"

typedef struct s_top_mid_bot
{
	int	t;
	int	m;
	int	b;
}				t_t_m_b;

typedef struct s_index
{
	int	index[1000];
	int	smallest;
	int	biggest;
}				t_index;


typedef struct s_ints_for_2
{
	int	i;
	int	j;
	int	znak;
	int	n;
	int	index;
}				t_ints_for_2;

typedef struct s_stacks
{
	int	stack_a[1000];
	int	stack_b[1000];
	t_t_m_b		value;
	t_ints_for_2	ints;
	t_index			index;
}				t_stacks;

int		error_case(char *s);
void	check_input(char **array);
void	adding_digits_to_stack(char **argv, t_stacks *stack);

void	sort_stack(int ac, t_stacks *stack);
void	algorithm_for_3_numbers(t_stacks *stack);
void	algorithm_brazhnik(t_stacks *stack, int ac);

int		printing_instructions(char *s);

#endif