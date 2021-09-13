#include "push_swap.h"

static void	check_if_stack_is_sorted(t_stacks *stack, int ac)
{
	stack->ints.i = 0;
	while (stack->ints.i < ac)
	{
		if (stack->stack_a[stack->ints.i] < stack->stack_a[stack->ints.i + 1])
			stack->ints.i++;
		else
			return ;
	}
	exit (0);
}

void	algorithm_brazhnik(t_stacks *stack, int ac)
{
	check_if_stack_is_sorted(stack, ac);
	finfing_the_smallest(stack, ac);
}
