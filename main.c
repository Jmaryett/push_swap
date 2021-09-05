#include "push_swap.h"

static void	filling_stack_a(t_stacks *stack)
{
	int	i;

	i = -1;
	while(stack->stack_a[++i])
		stack->stack_a[i] = -1;
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc < 4)
		error_case("Error\nWrong input.");
	filling_stack_a(&stack);
	check_input(argv);
	adding_digits_to_stack(argv, &stack);
	return (0);
}