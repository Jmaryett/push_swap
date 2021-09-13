#include "push_swap.h"

void	adding_digits_to_stack(char **argv, t_stacks *stack)
{
	stack->ints.i = 0;
	stack->ints.znak = 1;
	stack->ints.index = 0;
	stack->ints.n = 0;

	while (argv[++stack->ints.i])
	{
		stack->ints.j = 0;
		while (argv[stack->ints.i][stack->ints.j] == ' ')
			stack->ints.j++;
		while (argv[stack->ints.i][stack->ints.j] && (argv[stack->ints.i][stack->ints.j] >= '0' && argv[stack->ints.i][stack->ints.j] <= '9'))
		{
			if (argv[stack->ints.i][stack->ints.j - 1] == '-')
				stack->ints.znak = -1;
			stack->ints.n = stack->ints.znak * (stack->ints.n * 10 + (argv[stack->ints.i][stack->ints.j] - '0'));
			stack->stack_a[stack->ints.index] = stack->ints.n;
			stack->ints.j++;
		}
			stack->ints.znak = 1;
			stack->ints.n = 0;
			stack->ints.index++;
		}
}