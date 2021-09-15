#include "push_swap.h"

int	lstsize(t_stack_a *begin)
{
	int	len;
	t_stack_a	*tmp;

	if (!begin)
		return (0);
	tmp = begin;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
