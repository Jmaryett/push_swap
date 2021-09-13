#include "push_swap.h"

void	finding_the_smallest(t_stacks *stack, int len)
{
	int	smallest;

	stack->ints.i = 1;
	smallest = stack->stack_a[0];
	while (stack->ints.i < len)
	{
		if (stack->stack_a[stack->ints.i] < smallest)
			smallest = stack->stack_a[stack->ints.i];
		stack->ints.i++;
	}
	stack->index.smallest = smallest;
}