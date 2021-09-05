#include "push_swap.h"

void	adding_digits_to_stack(char **argv, t_stacks *stack)
{
	int	i;
	int	j;
	int	znak;
	int	n;
	int	index;

	i = 0;
	j = 0;
	znak = 1;
	index = 0;
	while (argv[++i])
	{
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] >= '0' && argv[i][j] <= '9')
		{
			if (argv[i][j - 1] == '-')
				znak = -1;
			while (argv[i][j] != '-' || argv[i][j] != ' ')
			{
				n = znak * (n * 10 + (argv[i][j] - '0'));
				stack->stack_a[index] = n;
				index++;
				j++;
			}
		}
	}
}
