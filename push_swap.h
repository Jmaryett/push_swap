#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "./libft/libft.h"

#ifndef INT_MAX
# define INT_MAX 2147483646
#endif


#ifndef INT_MIN
# define INT_MIN -2147483647
#endif

typedef struct s_stack_a
{
	int	number;
	int	index;
	int	flag;
	struct s_stack_a *next;
}				t_stack_a;

int		error_case(char *s);
void	check_input(char **array);

void	filling_stack_a(char **array, t_stack_a **begin_list_a);
void	check_if_stack_is_sorted(t_stack_a *begin);
void	indexation(t_stack_a **begin);

int	lstsize(t_stack_a *begin);
void	free_memory_lst(t_stack_a *new);


#endif