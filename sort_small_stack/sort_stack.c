#include "push_swap.h"

void	sort_stack(int ac, t_stacks *stack)
{
	if (ac == 3)
		algorithm_for_3_numbers(stack);
	else
		algorithm_brazhnik(stack, ac);
}