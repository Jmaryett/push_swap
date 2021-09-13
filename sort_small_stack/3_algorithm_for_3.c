#include "push_swap.h"

static void	check_if_stack_is_sorted(t_stacks *stack)
{
	stack->ints.i = 0;
	while (stack->ints.i < 2)
	{
		if (stack->stack_a[stack->ints.i] < stack->stack_a[stack->ints.i + 1])
			stack->ints.i++;
		else
			return ;
	}
	exit (0);
}

static void	sorting_stack_3(t_stacks *stack)
{
	stack->value.t = stack->stack_a[0];
	stack->value.m = stack->stack_a[1];
	stack->value.b = stack->stack_a[2];
	if (stack->value.t > stack->value.m && stack->value.t < 
		stack->value.b && stack->value.m < stack->value.b)
			printing_instructions("sa\n");
	else if (stack->value.t > stack->value.m && stack->value.t >
			stack->value.b && stack->value.m > stack->value.b)
				printing_instructions("sa\nrra\n");
	else if (stack->value.t > stack->value.m && stack->value.t >
			stack->value.b && stack->value.m < stack->value.b)
				printing_instructions("ra\n");
	else if (stack->value.t < stack->value.m && stack->value.t <
			stack->value.b && stack->value.m > stack->value.b)
				printing_instructions("sa\nra\n");
	else if (stack->value.t < stack->value.m && stack->value.t >
			stack->value.b && stack->value.m > stack->value.b)
				printing_instructions("rra\n");
}

void	algorithm_for_3_numbers(t_stacks *stack)
{
	check_if_stack_is_sorted(stack);
	sorting_stack_3(stack);
}